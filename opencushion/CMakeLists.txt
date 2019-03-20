cmake_minimum_required(VERSION 3.0)

project(myproj)
add_executable(myprojexe hx711.cpp)
target_link_libraries(myprojexe wiringPi)


