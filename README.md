# Logistics Robot
Made for Cognitive Robotics by João Sousa and Nuno Marques

## How to connect the computer to the robot and run ROS
NOTE: Make sure to change the hosts file (/etc/hosts) to contain the correct IP address of orangepipcplus, by adding the line `XXX.XXX.XXX.XXX orangepipcplus`.
### Wired connection
1. Connect gamepad to the computer via Bluetooth
2. Connect the computer to the robot via ethernet cable
3. Configure the robot's IP address in wired network settings
4. Run `$ ssh group01@192.168.0.234` in the computer's console
5. Run `$ tmux` in the computer's console
6. Run `$ roscore` in tmux
7. Run `$ roslaunch nomadic_driver robot.launch` in tmux
8. Run `$ env | grep ROS` in the computer's terminal and check the port of `ROS_MASTER_URI`
9. In each new window of the computer's terminal, start by running `$ export ROS_MASTER_URI=http://192.168.0.234:11311/`
10. Use `sftp://group01@192.168.0.234` in the file explorer to access the robot's files

### Wireless connection
1. Connect gamepad to the computer via Bluetooth
2. Connect to the robots network, nomadb.
3. Run `$ ssh group01@10.42.0.1` in the computer's console
4. Run `$ tmux` in the computer's console
5. Run `$ roscore` in tmux
6. Run `$ roslaunch nomadic_driver robot.launch` in tmux
7. Run `$ env | grep ROS` in the computer's terminal and check the port of `ROS_MASTER_URI`
8. In each new window of the computer's terminal, start by running `$ export ROS_MASTER_URI=http://10.42.0.1:11311/`
9.  Use `sftp://group01@10.42.0.1` in the file explorer to access the robot's files

### How to check IP address of the robot
1. Connect to the robots network, nomadb, or connect to it via ethernet cable.
2. Run `$ sudo apt install net-tools`
3. Run `$ ifconfig` and check the first 3 numbers of the your IP address under `wlp3s0`
4. Run `$ sudo snap install nmap`
5. Run `$ nmap -sP [first 3 IP address numbers].0/24` and check the IP address of `_gateway`. That is the robots IP address

## How to save a map
### In simulation
1. Run `$ roscore` in the computer
2. Open new terminal and run `$ roslaunch museum_guide mapping_sim.launch joycon:=true` (leave out the joycon part to use the keyboard instead)
3. Move the robot around. The deadman switch is X for a DualShock 4
4. Open new terminal and run `$ rosrun map_server map_saver -f map_name`. The map will be saved in the current directory.

### In the real world
1. Run `$ roscore` in the computer
2. Open new terminal and run `$ roslaunch museum_guide mapping_real.launch joycon:=true` (leave out the joycon part to use the keyboard instead)
3. Move the robot around. The deadman switch is X for a DualShock 4
4. Open new terminal and run `$ rosrun map_server map_saver -f map_name`. The map will be saved in the current directory.