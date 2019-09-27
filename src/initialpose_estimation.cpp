#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

void getInitialPose(const geometry_msgs::PoseWithCovarianceStamped& msg)
{
  ROS_INFO("pos.x = %f",msg.pose.pose.position.x);
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "initialpose_estimation");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/initialpose", 5, getInitialPose);

  ros::spin();

  return 0;
}
