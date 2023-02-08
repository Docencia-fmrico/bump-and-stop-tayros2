// Copyright 2021 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "tyros2_bt_bumpstop/IsObstacle.hpp"

#include <string>
#include <utility>

#include "behaviortree_cpp_v3/behavior_tree.h"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

const int KOBUKI_LASER_MEASURES = 360;
const int TIAGO_LASER_MEASURES = 666;

namespace tyros2_bt_bumpstop
{

using namespace std::chrono_literals;
using namespace std::placeholders;

IsObstacle::IsObstacle(const std::string & xml_tag_name, const BT::NodeConfiguration & conf)
: BT::ConditionNode(xml_tag_name, conf)
{
  config().blackboard->get("node", node_);

  laser_sub_ = node_->create_subscription<sensor_msgs::msg::LaserScan>(
    "/input_scan", 100, std::bind(&IsObstacle::laser_callback, this, _1));
  last_reading_time_ = node_->now();
}

void IsObstacle::laser_callback(sensor_msgs::msg::LaserScan::UniquePtr msg)
{
  last_scan_ = std::move(msg);
}

BT::NodeStatus IsObstacle::tick()
{
  if (last_scan_ == nullptr) {
    return BT::NodeStatus::FAILURE;
  }

  double distance = 1.0;
  int central_laser;
  getInput("distance", distance);
  
  int max_range_val;


  if (last_scan_->ranges.size() == KOBUKI_LASER_MEASURES) {
    for(int i = 0; i < KOBUKI_LASER_MEASURES/4; i++){
      if(!std::isnan(last_scan_->ranges[i]) && last_scan_->ranges[i] < distance){
        return BT::NodeStatus::SUCCESS;
        }
      } 
      for(int i = 270; i < KOBUKI_LASER_MEASURES; i++){
      if(!std::isnan(last_scan_->ranges[i]) && last_scan_->ranges[i] < distance){
        return BT::NodeStatus::SUCCESS;
        }
      } 
    } 
  else if (last_scan_->ranges.size() == TIAGO_LASER_MEASURES) {
    for(int i = 0; i < last_scan_->ranges.size(); i++){
      if(!std::isnan(last_scan_->ranges[i]) && last_scan_->ranges[i] < distance){
        return BT::NodeStatus::SUCCESS;
        }
    } 
  }
  
  return BT::NodeStatus::FAILURE;

}
}  // namespace tyros2_bt_bumpstop

#include "behaviortree_cpp_v3/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<tyros2_bt_bumpstop::IsObstacle>("IsObstacle");
}
