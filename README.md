[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6870050&assignment_repo_type=AssignmentRepo)
# bump-and-stop-tayros2

<div align="center">
<img width=300px src="https://github.com/Docencia-fmrico/bump-and-stop-tayros2/blob/readme/resources/figures/tiago.jpg" alt="explode"></a>
</div>

<h3 align="center"> Visual Behavior </h3>

<div align="center">
<img width=100px src="https://img.shields.io/badge/status-finished-brightgreen" alt="explode"></a>
<img width=100px src="https://img.shields.io/badge/license-Apache-orange" alt="explode"></a>
<img width=90px src="https://img.shields.io/badge/team-TayRos2-yellow" alt="explode"></a>
</div>


## Table of Contents
- [Table of Contents](#table-of-contents)
- [Project Goal](#project-goal)
- [Continous Integration](#continous-integration)
- [Logic and functionality](#logic-and-functionality)
- [Behavior Tree diagram](#behavior-tree-diagram)
- [Launcher](#launcher)
- [Team](#team)
- [Licencia](#licencia)

## Project Goal

The aim of this project is to create a ROS2 application in order to make able a robot to do the following tasks:
 
  1. Move forward if there is no obstacle in front of the robot at less than one and a half meters.
  2. Turn if robot detects an obstacle in front of him at less than one and a half meters.

This behaviour must work in simulator, kobuki robot or Tiago robot. In addition, the repository must contain a package with all the nodes, following the recommended indications and organization of repositories.

## Continous Integration

In order to follow the style guide, a continous integration system has been created in the GitHub repository to keep the code changes properly in the same code style.

In the **main.yaml** file of the workflows directory we have indicated to run the continous-integration-system any time a member create a pull-request or push changes in the main branch:

-----------------------------------------------------------------------
Snippet(.github/workflows/main.yaml):
``` yaml
name: main

on:
  pull_request:
    branches:
      - main
  push:
    branches:
      - main
```
-----------------------------------------------------------------------

This will run the apt-get update and installation commands before compiling the indicated package 

## Logic and functionality
The logic of this program is based on the one we saw as an example in class, which can be found in the [following repository](https://github.com/fmrico/book_ros2/tree/main/br2_bt_bumpgo).

The main difference is that being a bump and stop and not a bump and go, the backward movement is eliminated and the behavior tree is modified as we will see later.

In addition, a greater laser range has been used to detect if there is an obstacle in front of us in order to avoid more difficult to detect obstacles such as table legs.
In order to use the same code for both robots, since they return the sensor information of the laser in a different way, it has been necessary to adjust the verification of the measured distance depending on the robot in operation.

Once we carried out the tests with the kobuki, we observed that sometimes the laser returned certain erroneous values that generated bad behavior. To solve this, the number of rays that hit a nearby obstacle is counted and it is considered valid once it exceeds a threshold.

Below you can see the behavior of both robots in the simulator:\n

[Kobuki](https://urjc-my.sharepoint.com/:i:/g/personal/i_porras_2020_alumnos_urjc_es/EXVMmvkCCJZBtpa2jxzttPABY6VZBY-V71muGdSRGfFyzw)


[Tiago](https://urjc-my.sharepoint.com/:i:/g/personal/i_porras_2020_alumnos_urjc_es/EenZVRT0luBMiDdr4DpoVywB02wBP9NeRiz9TUlyBtlH2g)


## Behavior Tree Diagram 

You can see the Behaviour Tree diagram made in **Groot**:

<div align="center">
<img width=500px src="https://github.com/Docencia-fmrico/bump-and-stop-tayros2/blob/readme/resources/figures/beh-tree.png" alt="explode"></a>
</div>

Basically, it is a reactive sequence where it enters in a reactive fallback. We check if there is an obstacle at less than the distance specified. If it is, we jump to the turn behaviour. In the moment when there is no obstacle at less than the specified distance, we enter in the Forward behaviour.

## Launcher

To simplify the launch of the nodes and the remapping of the topcis, a launcher has been created for each of the robots. 

Below you can see the launcher used for the kobuki as an example:

-----------------------------------------------------------------------
``` python
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
``` 
-----------------------------------------------------------------------

## Tests
We performed tests to ensure the proper functioning of the various nodes in the behavior tree. We also used the copyright and style testing.

To make a test, the first step is create a simplifed bt:
-----------------------------------------------------------------------
``` c++
  BT::BehaviorTreeFactory factory;
  BT::SharedLibrary loader;

  factory.registerFromPlugin(loader.getOSName("tyros2_is_obstacle_bt_node"));

  std::string xml_bt =
    R"(
    <root main_tree_to_execute = "MainTree" >
      <BehaviorTree ID="MainTree">
          <IsObstacle distance="1.0"/>
      </BehaviorTree>
    </root>)";

  auto blackboard = BT::Blackboard::create();
  blackboard->set("node", node);
  BT::Tree tree = factory.createTreeFromText(xml_bt, blackboard);
``` 
-----------------------------------------------------------------------

In the obstacle_bt_test, we send a low-valued laser, and the BT node should return "SUCCESS" (indicating that the object is close). However, if the values are high (indicating that the object is far away), the BT node should return "FAILURE".

## Team

<div align="center">
<img width=200px src="https://github.com/Docencia-fmrico/bump-and-stop-tayros2/blob/readme/resources/figures/logo.png" alt="explode"></a>
</div>

- [Adrian Cobo](https://github.com/AdrianCobo)
- [Adrian Madinabeitia](https://github.com/madport)
- [Ivan Porras](https://github.com/porrasp8)
- [Saul Navajas](https://github.com/SaulN99)

## Licencia 
<a rel="license" href="https://www.apache.org/licenses/LICENSE-2.0"><img alt="Apache License" style="border-width:0" src="https://www.apache.org/img/asf-estd-1999-logo.jpg" /></a><br/>(TayROS2) </a><br/>This work is licensed under a <a rel="license" href="https://www.apache.org/licenses/LICENSE-2.0">Apache license 2.0

