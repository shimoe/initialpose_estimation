#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include <bits/stdc++.h>
#include <random>


void getInitialPose(const geometry_msgs::PoseWithCovarianceStamped& msg)
{
  ROS_INFO("pos.x = %f",msg.pose.pose.position.x);
  std::ramdom_device seed;
  std::mt19937 engine(seed());            // メルセンヌ・ツイスター法
  // std::minstd_rand0 engine(seed());    // 線形合同法
  // std::ranlux24_base engine(seed());   // キャリー付き減算法

  double mu = 0.0, sig = 1.0;

  mu = msg.pose.pose.position.x;
  std::normal_distribution<> dist(mu, sig);

  int n = 1000000;
  std::vector<double> list(n);

  for (int i=0; i<n; ++i) {
    list[i] = dist(engine);
  }

  // 小領域に区切って、その中の乱数の個数を数える
  std::vector<double> numbers, x;
  double range = mu + sig * 5.0;
  double step = 0.1;

  for (double i=-range; i<=range; i+=step) {
    int number = 0;
    for (auto& el : list) {
      if (i-step/2.0 < el && el <= i+step/2.0) {
        ++number;
      }
    }
    x.push_back(i);
    numbers.push_back(number);
  }

  ROS_INFO(x);
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "initialpose_estimation");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/initialpose", 5, getInitialPose);

  ros::spin();

  return 0;
}
