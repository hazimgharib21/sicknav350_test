#include <ros/ros.h>
#include <sstream>
#include <sicktoolbox/SickNAV350.hh>

using namespace std;
using namespace SickToolbox;

int main(int argc, char *argv[]){

  ros::init(argc, argv, "sicknav350");
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);

  int count = 0;

  while(ros::ok()){

    string msg;
    stringstream ss;
    ss << count;
    msg = ss.str();

    ROS_INFO("%s", msg.c_str());

    

    ros::spinOnce();
    loop_rate.sleep();

    ++count;
    
  
  }
}
