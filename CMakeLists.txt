cmake_minimum_required(VERSION 2.8.3)
project(sicknav350_test)

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs sensor_msgs nav_msgs geometry_msgs sicktoolbox rosconsole diagnostic_updater tf message_generation)

generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
 INCLUDE_DIRS
 LIBRARIES
 CATKIN_DEPENDS roscpp std_msgs sensor_msgs nav_msgs geometry_msgs sicktoolbox rosconsole diagnostic_updater tf message_runtime move_base_msgs actionlib
 DEPENDS
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(sicknav350 src/sicknav350.cpp)
target_link_libraries(sicknav350 ${catkin_LIBRARIES})
add_dependencies(sicknav350 sicknav350_gencpp)

install(TARGETS sicknav350
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})



