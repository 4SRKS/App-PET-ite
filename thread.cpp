#include <iostream>
#include <thread>
#include "keypad.cpp"
#include "PWM.cpp"
#include "mcp3008SpiTest.cpp"

using namespace std;

void Keys()
{
int a;
while(1){
a=keypad(19,13,6,5,4,17,27,22);}
}

void Motor()
{
int b;
b=motor_Run();
}

void Water_Level_Update()
{
int c;
while(1){
c=WaterLevel();
}
}

int main()
{
 std::thread first (Keys);
 std::thread second (Motor);
 std::thread third (Water_Level_Update);
 
 first.join();
 second.join();
 third.join();
 
 return 0;
}



