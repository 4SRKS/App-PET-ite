#include <iostream>
#include <thread>
#include "keypad.cpp"
#include "PWM.cpp"
#include "mcp3008SpiTest.cpp"
#include "hx711.cpp"

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

void load_cell()
{
	int d;
	while(1){
		d=loadcell();
	}
}


int main()
{
 std::thread first (Keys);
 std::thread second (Motor);
 std::thread third (Water_Level_Update);
 std::thread fourth (load_cell);
 
 first.join();
 second.join();
 third.join();
 fourth.join();
 
 return 0;
}




