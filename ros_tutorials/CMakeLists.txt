cmake_minimum_required(VERSION 3.0.2)
project(ros_tutorials)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  roscpp
  std_msgs
)

##########Your code here#############
add_message_files(
    FILES
    RV.msg)

generate_messages(
    DEPENDENCIES
    std_msgs
)
######################################

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES ros_tutorials
  CATKIN_DEPENDS geometry_msgs roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

##########Your code here#############
add_executable(circular_motion_publisher src/circular_motion_publisher.cpp)
add_dependencies(circular_motion_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(circular_motion_publisher ${catkin_LIBRARIES})
#####################################
