cmake_minimum_required(VERSION 3.0)

project(myproj)
add_executable(mypjex thread.cpp)
target_link_libraries(mypjex wiringPi)