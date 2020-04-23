#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {

	ros::init(argc, argv, "parrot_publisher");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::String>("/strings",10);
	//ros::Rate rate(10);
	
	while(ros::ok){
	
		std_msgs::String in_string;
		cout<<" Input : ";
		cin>>in_string.data;
		ROS_INFO("%s", in_string.data.c_str());
		pub.publish(in_string);
		//rate.sleep();
	}


	return 0;

}
