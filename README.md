Made for Cognitive Robotics 2021/2022 by João Sousa and Nuno Marques, Masters Degree in Robotics, A.I. and Control, DEEC @ UC

## Table of contents<!-- omit in toc -->
- [How to connect the computer to the robot and run ROS<a name = "connect_pc_to_robot"></a>](#how-to-connect-the-computer-to-the-robot-and-run-ros)
  - [Wired connection<a name = "wired_connection"></a>](#wired-connection)
  - [Wireless connection<a name = "wireless_connection"></a>](#wireless-connection)
  - [How to check IP address of the robot<a name = "check_ip"></a>](#how-to-check-ip-address-of-the-robot)
- [How to save a map<a name = "save_map"></a>](#how-to-save-a-map)
  - [In simulation<a name = "save_map_sim"></a>](#in-simulation)
  - [In the real world](#in-the-real-world)

## How to connect the computer to the robot and run ROS<a name = "connect_pc_to_robot"></a>
NOTE: Make sure to change the hosts file (/etc/hosts) to contain the correct IP address of orangepipcplus, by adding the line `XXX.XXX.XXX.XXX orangepipcplus`.

### Wired connection<a name = "wired_connection"></a>
1. Connect gamepad to the computer via Bluetooth.
2. Connect the computer to the robot via ethernet cable.
3. Configure the robot's IP address in wired network settings.
4. Run `$ ssh group01@192.168.0.234` in the computer's console. The password is `1234`.
5. Run `$ tmux` in the computer's console.
6. Run `$ roscore` in tmux.
7. Run `$ roslaunch nomadic_driver robot.launch` in tmux.
8. Run `$ env | grep ROS` in the computer's terminal and check the port of `ROS_MASTER_URI`.
9.  In each new window of the computer's terminal, start by running `$ export ROS_MASTER_URI=http://192.168.0.234:11311/`.
10. Use `sftp://group01@192.168.0.234` in the file explorer to access the robot's files. The password is `1234`.

### Wireless connection<a name = "wireless_connection"></a>
1. Connect gamepad to the computer via Bluetooth.
2. Connect to the robots network, nomadb. The password is `scout1234`.
3. Run `$ ssh group01@10.42.0.1` in the computer's console. The password is `1234`.
4. Run `$ tmux` in the computer's console.
5. Run `$ roscore` in tmux.
6. Run `$ roslaunch nomadic_driver robot.launch` in tmux.
7. Run `$ env | grep ROS` in the computer's terminal and check the port of `ROS_MASTER_URI`.
8. In each new window of the computer's terminal, start by running `$ export ROS_MASTER_URI=http://10.42.0.1:11311/`.
9.  Use `sftp://group01@10.42.0.1` in the file explorer to access the robot's files. The password is `1234`.

### How to check IP address of the robot<a name = "check_ip"></a>
1. Connect to the robots network, nomadb, or connect to it via ethernet cable.
2. Run `$ sudo apt install net-tools`.
3. Run `$ ifconfig` and check the first 3 numbers of the your IP address under `wlp3s0`.
4. Run `$ sudo snap install nmap`.
5. Run `$ nmap -sP [first 3 IP address numbers].0/24` and check the IP address of `_gateway`. That is the robots IP address.

## How to save a map<a name = "save_map"></a>
### In simulation<a name = "save_map_sim"></a>
1. Run `$ roscore` in the computer.
2. Open new terminal and run `$ roslaunch museum_guide mapping_sim.launch joycon:=true` (leave out the joycon part to use the keyboard instead).
3. Move the robot around. The deadman switch is X for a DualShock 4.
4. Open new terminal and run `$ rosrun map_server map_saver -f map_name`. The map will be saved in the current directory.

### In the real world
1. Run `$ roscore` in the computer.
2. Open new terminal and run `$ roslaunch museum_guide mapping_real.launch joycon:=true` (leave out the joycon part to use the keyboard instead).
3. Move the robot around. The deadman switch is X for a DualShock 4.
4. Open new terminal and run `$ rosrun map_server map_saver -f map_name`. The map will be saved in the current directory.