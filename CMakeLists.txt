cmake_minimum_required(VERSION 3.0.2)
project(museum_guide)

set (OpenCV_DIR /usr/lib/x86_64-linux-gnu/cmake/opencv4)

## Compile as C++11, supported in ROS Kinetic and newer
#add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  OpenCV
  pcl_ros
  
)


## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(explorer_node src/explorer_node.cpp)
####add_executable(guide_node src/guide_node.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(explorer_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
####add_dependencies(guide_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(explorer_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)

####target_link_libraries(guide_node
####  ${catkin_LIBRARIES}
####  ${OpenCV_LIBS}
####)
