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


### Kobuki

### Tiago


## Behavior Tree Diagram 

You can see the Behaviour Tree diagram made in **Groot**:

<div align="center">
<img width=500px src="https://github.com/Docencia-fmrico/bump-and-stop-tayros2/blob/readme/resources/figures/beh-tree.png" alt="explode"></a>
</div>



## Launcher


## Team

<div align="center">
<img width=200px src="https://github.com/Docencia-fmrico/bump-and-stop-tayros2/blob/readme/resources/figures/logo.png" alt="explode"></a>
</div>

- [Adrian Cobo](https://github.com/AdrianCobo)
- [Adrian Madinabeitia](https://github.com/madport)
- [Ivan Porras](https://github.com/porrasp8)
- [Saul Navajas](https://github.com/SaulN99)

## Licencia 
<a rel="license" href="https://www.apache.org/licenses/LICENSE-2.0"><img alt="Apache License" style="border-width:0" src="https://www.apache.org/img/asf-estd-1999-logo.jpg" /></a><br/>(TayRos) </a><br/>This work is licensed under a <a rel="license" href="https://www.apache.org/licenses/LICENSE-2.0">Apache license 2.0

