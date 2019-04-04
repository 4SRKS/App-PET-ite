#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "gpio-sysfs.h"
#include "gpio-sysfs.cpp"

#include <iostream>
using namespace std;

int keypad(unsigned int in1, unsigned int in2, unsigned int in3, unsigned int in4, unsigned int out1, unsigned int out2, unsigned int out3, unsigned int out4$
        //Declaring the outputs
        unsigned int drdy5_GPIO = out1;
        unsigned int drdy6_GPIO = out2;
        unsigned int drdy7_GPIO = out3;
        unsigned int drdy8_GPIO = out4;

        //Declaring the input GPIOs
        unsigned int drdy1_GPIO = in4;
        unsigned int drdy2_GPIO = in3;
        unsigned int drdy3_GPIO = in2;
        unsigned int drdy4_GPIO = in1;

        //Declaring the addresses where the input value will be stored
        unsigned int *sysfs_fd1;
        unsigned int *sysfs_fd2;
        unsigned int *sysfs_fd3;
        unsigned int *sysfs_fd4;

        //Varibles to associate the addresses to the sysfs variables
        unsigned int value1;
        unsigned int value2;
        unsigned int value3;
        unsigned int value4;

                //Associating the addreses to the memory registors
                sysfs_fd1=&value1;
                sysfs_fd2=&value2;
                sysfs_fd3=&value3;
                sysfs_fd4=&value4;

                //Setting GPIOs as output
                gpio_export(drdy5_GPIO);
                gpio_set_dir(drdy5_GPIO,1);
                gpio_set_value(drdy5_GPIO,0);

                gpio_export(drdy6_GPIO);
                gpio_set_dir(drdy6_GPIO,1);
                gpio_set_value(drdy6_GPIO,0);

                gpio_export(drdy7_GPIO);
                gpio_set_dir(drdy7_GPIO,1);
                gpio_set_value(drdy7_GPIO,0);

                gpio_export(drdy8_GPIO);
                gpio_set_dir(drdy8_GPIO,1);
                gpio_set_value(drdy8_GPIO,0);

                //Setting GPIOs as input
                gpio_export(drdy1_GPIO);
                gpio_set_dir(drdy1_GPIO,0);

                gpio_export(drdy2_GPIO);
                gpio_set_dir(drdy2_GPIO,0);

                gpio_export(drdy3_GPIO);
                gpio_set_dir(drdy3_GPIO,0);

                gpio_export(drdy4_GPIO);
                gpio_set_dir(drdy4_GPIO,0);
                //Declaring Array of Keppad Buttons
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
                                //if(myval<=9){
                                //cout<<keys[k][t]<<endl;}
                                usleep(500000);
                                p=0;
                                }
                        }
                        gpio_set_value(outputs[t],0);
                }
        }
return myval;
}

int Keys_weight()
{
int a;
int counter=0;
int u=1;
int values[4]={0,0,0,0};
int total=0;
cout<<"Please enter the weight in grams: "<<endl;
//Getting the Input From the user about grams
while(u){
        if(counter==4){
                break;}
        a=keypad(12,16,20,21,26,19,13,6);
        if(a==15){
                break;}
        if(a!=15){
                values[counter]=a;
                counter=counter+1;}
        }
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
           
int Keys_verify_weight()
{
   int b;
   int ret=0;
   cout<<"If value is correct please press A"<<endl;
   //cout<<"If value is incorrect please press B"<<endl;
   b=keypad(12,16,20,21,26,19,13,6);
   if(b==12)
        {return 1;}
   else{return 0;}
}

int Keys_time()
{
int time;
cout<<"Please enter the time between feedings in hours: "<<endl;
time=keypad(12,16,20,21,26,19,13,6);
cout<<"You have entered: "<<time<<" hours"<<endl;
return time;
}

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


