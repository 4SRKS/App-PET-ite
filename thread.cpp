#include <iostream>
#include <thread>
#include "keypad.cpp"
#include "PWM.cpp"
#include "mcp3008SpiTest.cpp"
#include "hx711.cpp"

using namespace std;
int awake=0;

int abc();

void Motor()
{
unsigned int b;
motor_Run_time(67000);
}

void Water_Level_Update()
{
int c;
while(1){
c=WaterLevel();
//cout<<c<<endl;
if (c<100){
	cout<<" refill to max level"<<endl;
}
usleep(15000000);
if(awake=1){
	break;}
}
}

void Timekeeper(int hours)
{
int seconds=hours*60;
for(int t=seconds;t>=0;t--){
usleep(1000000);
cout<< "timer"<<t<<endl;
}
cout<<"I am awake"<<endl;
awake=1;
}

void counter(){
 while(1){
 	if(awake==0){
             cout<<"Sleeping"<<endl;
             usleep(1000000);
             	     }
        else{break;}
         }
}
void load_cell()
{
int d;

d=abc();

}


int main()
{
 

 
 //Initializing the Food Dispenser through user input 
 cout<<"Welcome to App-PET-ite"<<endl;

 //First getting the Weight Input
 int weight;
 int status_w;
 while(1){
 weight=Keys_weight();
 status_w=Keys_verify_weight();
 if(status_w==1){
 		break;}
 }
 cout<<"Weight successfully stored"<<endl;

 //Getting the Time Input
 int time;
 int status_t;
 while(1){
 time=Keys_time();
 status_t=Keys_verify_time();
 if(status_t==1){
 		break;}
 }
 cout<<"Time successfully stored"<<endl;

 while(1)
 {
	 int b;
	 b=abc();
	 cout<<"weight"<<(b-45)<<endl;
	 usleep(1000);
	 if((b-45)<=weight)
	 {
		motor_Run_time(67000); 
		//usleep(1000);
	 }
	 if((b-45)>weight)
	 {
		 break;
     }
 }		 
		 cout<<"Food set to desired limit"<<endl;
while(1)
{		 
		 std::thread first (Timekeeper,time);
		 std::thread second (Water_Level_Update);
		 
		 first.join();
		 second.join();
		 usleep(1000);
		 awake = 0;
		 int c;
	     c=abc();
	     cout<<(c-45)<<endl;
	     usleep(1000);
	     if((c-45)<=weight)
	     {
		 motor_Run_time(67000); 
		 //usleep(1000);
	     }
	     
		 //usleep(1000);
		 if((c-45)>weight)
		 {
			cout<<"Food set to desired limit"<<endl;
			
		 
	     }
	     
	 
}
	 
 return 0;
}






