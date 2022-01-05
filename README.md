# Logistics Robot
Made for Cognitive Robotics by João Sousa and Nuno Marques

## How to connect the computer to the robot and run ROS
1. Connect gamepad to the computer via Bluetooth
2. Connect the computer to the robot via ethernet cable
3. Configure the robot's IP address in wired network settings
4. Run `$ ssh group01@192.168.0.234` in the computer's console
5. Run `$ tmux` in the computer's console
6. Run `$ roscore` in tmux
7. Run `$ roslaunch nomadic_driver robot.launch` in tmux
8. Run `$ env | grep ROS` in the computer's terminal and check the port of `ROS_MASTER_URI`
9. In each new window of the computer's terminal, start by running `$ export ROS_MASTER_URI=hhtp://192.168.0.234:11311/`
10. Use `sftp://group01@192.168.0.234` in the file explorer to access the robot's files

## How to save a map in simulation
1. Run `$ roscore`
2. Open new terminal and run `$ roslaunch museum_guide mapping_sim.launch joycon:=true` (leave out the joycon part to use the keyboard instead)
3. Move the robot around in Gazebo with the joystick. The deadman switch is X for a DualShock 4
4. Open new terminal and run `$ rosrun map_server map_saver -f map_name`. The map will be saved in the current directory.
