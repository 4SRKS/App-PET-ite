/********************
* The header files
*********************/
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <iostream>
using namespace std;

/*************************************************************************************************************************************
* Using the following libraries from https://github.com/berndporr/gpio-sysfs to set the GPIOs as Inputs and Outputs for the Keypad
**************************************************************************************************************************************/
#include "gpio-sysfs.h"
#include "gpio-sysfs.cpp"

/**************************************************************************************************************************************************************
* Keypad function declaration that initializes the Inputs and Outputs and then waits for a key to be pressed and then returns the value of the key pressed 
***************************************************************************************************************************************************************/
int keypad(unsigned int in1, unsigned int in2, unsigned int in3, unsigned int in4, unsigned int out1, unsigned int out2, unsigned int out3, unsigned int out4){
/************************************      
* Declaring the output GPIOs
*************************************/
unsigned int drdy5_GPIO = out1;
unsigned int drdy6_GPIO = out2;
unsigned int drdy7_GPIO = out3;
unsigned int drdy8_GPIO = out4;

/************************************
* Declaring the input GPIOs
*************************************/
unsigned int drdy1_GPIO = in4;
unsigned int drdy2_GPIO = in3;
unsigned int drdy3_GPIO = in2;
unsigned int drdy4_GPIO = in1;

/*************************************************************************
* Gpio-sysfs uses pointers to store the value of the Inputs
* So declaring the pointer where the keypad input values will be stored
**************************************************************************/
unsigned int *sysfs_fd1;
unsigned int *sysfs_fd2;
unsigned int *sysfs_fd3;
unsigned int *sysfs_fd4;

/****************************************************************
* Varibles to associate the addresses to the sysfs variables
*****************************************************************/
unsigned int value1;
unsigned int value2;
unsigned int value3;
unsigned int value4;

/***********************************************************************************************
* Allocating addresses of variables to the pointers. This is done to avoid segmentation fault
************************************************************************************************/
sysfs_fd1=&value1;
sysfs_fd2=&value2;
sysfs_fd3=&value3;
sysfs_fd4=&value4;
        
/**************************************
* Exporting the GPIOs
***************************************/
gpio_export(drdy5_GPIO);
gpio_export(drdy6_GPIO);
gpio_export(drdy7_GPIO);
gpio_export(drdy8_GPIO);

/**************************************
* Setting the GPIOs as Output
***************************************/
gpio_set_dir(drdy5_GPIO,1);
gpio_set_dir(drdy6_GPIO,1);
gpio_set_dir(drdy7_GPIO,1);
gpio_set_dir(drdy8_GPIO,1);

/**************************************
* Initializing the Output values as 0
***************************************/
gpio_set_value(drdy5_GPIO,0);               
gpio_set_value(drdy6_GPIO,0);               
gpio_set_value(drdy7_GPIO,0);
gpio_set_value(drdy8_GPIO,0);                
                
/**************************************
* Exporting the GPIOs
***************************************/
gpio_export(drdy1_GPIO);
gpio_export(drdy2_GPIO);                
gpio_export(drdy3_GPIO);                
gpio_export(drdy4_GPIO);                

/**************************************
* Setting GPIOs as input
***************************************/          
gpio_set_dir(drdy1_GPIO,0);
gpio_set_dir(drdy2_GPIO,0);
gpio_set_dir(drdy3_GPIO,0);
gpio_set_dir(drdy4_GPIO,0);

/**************************************               
* Declaring Array of Keppad Buttons
***************************************/
char keys[4][4]={{'1','2','3','A'},
                 {'4','5','6','B'},
                 {'7','8','9','C'},
                 {'*','0','#','D'}};
int keys_ret[4][4]={{1,2,3,12},
                    {4,5,6,13},
                    {7,8,9,14},
                    {10,0,11,15}};
int myval=0;
int val;
unsigned int outputs[4]={drdy5_GPIO,drdy6_GPIO,drdy7_GPIO,drdy8_GPIO};
unsigned int inputs[4]={drdy4_GPIO,drdy3_GPIO,drdy2_GPIO,drdy1_GPIO};
unsigned int *sys[4]={sysfs_fd4,sysfs_fd3,sysfs_fd2,sysfs_fd1};
int p=1;
        
/******************************************************************************************************************
* Defining the nested for loop that sequentially changes the value of the four outputs to Logic 1
* Once the output value is set to 1, the input values are checked one by one
* The input should be Logic 0 (because of the Pull down resistors) when no key is pressed
* The input turns to logic 1 when a key is pressed
* Depending on which output was 1 when a certain input became 1, the key which was pressed can be identified
* Once the key identified the return value is updated
* The loop breaks afte the first key is pressed.
* This function allows only one key pressed to be recognized.
* To get continous input from the Keypad, this fuction must be called continously
*******************************************************************************************************************/
while(p)
      {
      for (int t=0; t<=3; t++)
        {
        gpio_set_value(outputs[t],1);
        for (int k=0; k<=3; k++)
                {
                val=gpio_get_value(inputs[k],sys[k]);
                if(*sys[k]==1)
                        {
                        myval=keys_ret[k][t];
                        //cout<<keys[k][t]<<endl;
                        usleep(500000); //The delay is added to avoid multiple positive results when pressing the key once
                        p=0;
                        }
                 }
         gpio_set_value(outputs[t],0);
         }
      }
return myval;
}

/*********************************************************************************************************************
* This function takes Input from the user in grams
* The input represents the grams that will be dispensed at each feeding interval
* The maximum weight that can be entered is 2000 grams so the keypad function can be called a maximum of 4 times
* The user can enter a value in grams that is 1,2 or 3 digits long
* In that case the user needs to press D at the end of data entry
**********************************************************************************************************************/
int Keys_weight()
{
int a;
int counter=0;
int u=1;
int values[4]={0,0,0,0};
int total=0;
/*************************************************
* Promting the User to input data
**************************************************/
cout<<"Please enter the weight in grams: "<<endl;
/*************************************************
* Reading the User Input and storing it
**************************************************/
while(u){
        if(counter==4){
                break;}
        a=keypad(12,16,20,21,26,19,13,6); //The values of the Keypad inputs and outputs are fixed according to the PCB design
        if(a==15){
                break;}
        if(a!=15){
                values[counter]=a;
                counter=counter+1;}
        }
/************************************************************************************
* Converting the key presses into a value in grams and then returning that variable
*************************************************************************************/
if(counter==1){
        total=values[0];}
if(counter==2){
        total=(values[0]*10)+(values[1]);}
if(counter==3){
        total=(values[0]*100)+(values[1]*10)+(values[2]);}
if(counter==4){
        total=(values[0]*1000)+(values[1]*100)+(values[2]*10)+(values[3]);}

cout<<"You have entered: "<<total<<" grams"<<endl;
return total;
}

/************************************************************************
* This function verifies the weight entered in the previous function 
* The user needs to press A to verify the weight
* Returns 1 if verified othewise returns zero
*************************************************************************/
int Keys_verify_weight()
{
   int b;
   int ret=0;
   cout<<"If weight value is correct please press A"<<endl;
   b=keypad(12,16,20,21,26,19,13,6); //The values of the Keypad inputs and outputs are fixed according to the PCB design
   if(b==12)
        {return 1;}
   else{return 0;}
}

/*************************************************************************************************
* This function takes input from the user regarding the time after which food will be dispensed 
* The input is a one digit entry in hours
**************************************************************************************************/
int Keys_time()
{
int time;
/**********************************************
* Prompting the User to Input data
***********************************************/
cout<<"Please enter the time between feedings in hours: "<<endl;
/**********************************************
* Getting the Input, storing it and return it
***********************************************/
time=keypad(12,16,20,21,26,19,13,6);
cout<<"You have entered: "<<time<<" hours"<<endl;
return time;
}

/***********************************************************************
* This function verifies the time entered in the previous function 
* The user needs to press A to verify the time
* Returns 1 if verified othewise returns zero
************************************************************************/
int Keys_verify_time(){
   int b;
   int ret=0;
   cout<<"If time value is correct please press A"<<endl;
   //cout<<"If value is incorrect please press B"<<endl;
   b=keypad(12,16,20,21,26,19,13,6);
   if(b==12)
        {return 1;}
   else{return 0;}
}

