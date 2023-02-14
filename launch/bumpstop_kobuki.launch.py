# Copyright 2021 Intelligent Robotics Lab
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# input scan(real robot - simulated robot): /scan_filtered - /scan

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    bumpstop_cmp = Node(
        package='tyros2_bt_bumpstop',
        executable='bt_bumpstop',
        parameters=[{
          'use_sim_time': True,
        }],
        remappings=[
          ('input_scan', '/scan'),
          ('output_vel', '/cmd_vel')
        ],
        output='screen'
    )

    ld = LaunchDescription()

    # Add any actions
    ld.add_action(bumpstop_cmp)

    return ld
