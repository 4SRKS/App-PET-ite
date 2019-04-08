#include <iostream>
#include <thread>
#include "keypad.cpp"
#include "PWM.cpp"
#include "mcp3008SpiTest.cpp"
#include <fstream>
//#include <windows.h>
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
//fname = fp.open("wl.txt")
//fp<<c;
//fclose();

}
}

void Timekeeper(int hours){
int seconds=hours*60;
for(int t=seconds;t>=0;t--){
usleep(1000000);
}
cout<<"I am awake"<<endl;
awake=1;
}

void fooddispense(){
 while(1){
 	if(awake==0){
             cout<<"Sleeping"<<endl;
             usleep(1000000);
             	     }
        else{break;}
         }
}

int main()
{
 
 //Initializing the Food Dispenser through user input 
 cout<<"Welcome to App-PET-ite"<<endl;
 
 string line;
 ifstream myfile ("weight.txt");
 
 //if (myfile.is_open()){
   //     while (getline (myfile, line)) {
     //       cout << line << "\n";
       // }
       // myfile.close();
//}


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

 std::thread first (Timekeeper,time);
 std::thread second (fooddispense); 
 first.join();
 second.join();
 return 0;
}




