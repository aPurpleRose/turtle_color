# turtle_color
### Description
A simple ROS program that changes the background color when hitting the border of the canvas.

## Installation 
In order to install and run the program you will need to ROS Noetic on Ubuntu 20.04. Other versions may work, but weren't tested.
<br>
Here is a guide: http://wiki.ros.org/noetic/Installation/Ubuntu

### Turtlesim
Additionally, you will need the turtlesim package. Simply install it with <br> 
`$ sudo apt-get install ros-$(rosversion -d)-turtlesim`.

### Sourcing
For convenience you should add <br>
`$ source /opt/ros/noetic/setup.bash`<br>
to the bottom of your .bashrc in your home directory. If you choose not to, you will have to run this command in every new terminal you want to run ROS in.
<br>

### Catkin
Should you not already have a catkin workspace you can create one like so: <br>
```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make
```
If for some reason catkin isn't installed by default you can do so with <br> 
`$ sudo apt-get install ros-noetic-catkin`. Replace 'noetic' if you use a different ROS distro.
<br>
I recommend adding <br>
`$ source ~/catkin_ws/devel/setup.bash` <br>
to your .bashrc too. You won't need to run it when not using catkin, but it is more convenient.
<br>
<br>
Now you can download this package and move it into `~/catkin_ws/src`.

## Building
To build the package run 
`$ catkin_make`
inside of the `~/catkin_ws` folder.

## Usage
To start the program type `roslaunch turtle_color color.launch` in the terminal and press enter.
<br>
You should position the window of the terminal and the turtlesim so they don't overlap, because you need the terminal window to be focused in order to control the turtle.
