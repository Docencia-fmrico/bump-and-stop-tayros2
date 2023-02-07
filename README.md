# PCS-0-BumpStop
Ejercicio 1 de Planificación y Sistemas Cognitivos 2023

En grupos de 4, haced una aplicación en ROS 2 que haga que un robot:
1. Avance si no hay un obstáculo delante a menos de un metro y medio.
2. Gire si detecta un obstáculo delante a menos de un metro y medio.

El repositorio debe contener un paquete que contenga todos los nodos necesarios, siguiendo las recomendaciones de buenas prácticas y organización de los repositorios.

El robot debe funcionar en el [robot simulado](https://github.com/IntelligentRoboticsLabs/ir_robots), en Tiago o en Kobuki.

Puntuación (sobre 10):
* +8 correcto funcionamiento en el robot simulado.
* +1 correcto funcionamiento en el robot real.
* +2 Readme.md bien documentado con videos. 
* -3 Warnings o que no pase los tests.
* +1 Setup de CI/CD

De momento solo he cambiado los name_spaces y nombre del paquete del proyecto del libro del profeosr para que podamos seguir con nuestros cambios. 
Para ejecutar el programa: ros2 run tyros2_bt_bumpstop bt_bumpstop --ros-args -r input_scan:=/scan_raw -r output_vel:=/nav_vel -p use_sim_time:=true
