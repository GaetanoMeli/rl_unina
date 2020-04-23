#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <string>

using namespace std;

class ROS_SUB {

	public:
		ROS_SUB();
		void topic_cb(std_msgs::StringConstPtr data);
	private:
		ros::NodeHandle _nh;
		ros::Subscriber _topic_sub;
};


ROS_SUB::ROS_SUB(){
	
	_topic_sub = _nh.subscribe("/strings",0, &ROS_SUB::topic_cb, this);

}

void ROS_SUB::topic_cb(std_msgs::StringConstPtr data){

	ROS_INFO("Listener: %s", data->data.c_str());

}

int main(int argc, char **argv) {

	ros::init(argc, argv, "parrot_subscriber");
	ROS_SUB rs;
	ros::spin();
	return 0;

}
