#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "std_srvs/Empty.h"


void changeColor(const turtlesim::Pose pose)
{
  ros::NodeHandle nh("~");
  if (pose.x <= 0) {
    nh.setParam("/sim/background_r", 0);
    nh.setParam("/sim/background_g", 0);
    nh.setParam("/sim/background_b", 255);
  }
  if (pose.x >= 11) {
    nh.setParam("/sim/background_r", 0);
    nh.setParam("/sim/background_g", 255);
    nh.setParam("/sim/background_b", 0);
  }
  if (pose.y >= 11) {
    nh.setParam("/sim/background_r", 255);
    nh.setParam("/sim/background_g", 0);
    nh.setParam("/sim/background_b", 0);
  }
  if (pose.y <= 0) {
    nh.setParam("/sim/background_r", 255);
    nh.setParam("/sim/background_g", 165);
    nh.setParam("/sim/background_b", 0);
  }

  ros::ServiceClient clearClient = nh.serviceClient<std_srvs::Empty>("/clear");
  std_srvs::Empty srv;
  clearClient.call(srv);
  
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher pos_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
  ros::Subscriber pos = n.subscribe("/turtle1/pose", 1, changeColor);

  ros::Rate loop_rate(10);

  n.setParam("/sim/background_r", 255);
  n.setParam("/sim/background_g", 255);
  n.setParam("/sim/background_b", 255);

  int count = 0;
  while (ros::ok())
  {
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

