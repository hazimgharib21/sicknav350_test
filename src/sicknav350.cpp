#include <ros/ros.h>
#include <sstream>
#include <sicktoolbox/SickNAV350.hh>

using namespace std;
using namespace SickToolbox;

int main(int argc, char *argv[]){

  ros::init(argc, argv, "sicknav350");
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);

  string ipaddress = (std::string)DEFAULT_SICK_IP_ADDRESS;
  int port = DEFAULT_SICK_TCP_PORT;
  SickNav350 sick_nav350(ipaddress.c_str(), port);

  try {

    cout << "Initializing Sick Sensor..." << endl;

    cout << "IP Address : " << ipaddress << endl;
    cout << "Port : " << port << endl;
  
    sick_nav350.Initialize();
  }catch(...){

    ROS_ERROR("Configuration Error");
    return -1;
  
  }

  while(ros::ok()){
    

    ros::spinOnce();
    loop_rate.sleep();

    
  
  }
}
