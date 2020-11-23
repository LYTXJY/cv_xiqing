
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
# set(CMAKE_CXX_FLAGS “-std=c++11”)
# set(OpenCV_DIR /usr/local/include/) //默认安装位置
# set(OpenCV_FOUND 1)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )