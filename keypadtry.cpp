#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "gz_clk.h"
#include "gpio-sysfs.h"
#include "gpio-sysfs.cpp"

#include <iostream>
using namespace std;

//Declaring the outputs
unsigned int drdy5_GPIO = 4;
unsigned int drdy6_GPIO = 17;
unsigned int drdy7_GPIO = 27;
unsigned int drdy8_GPIO = 22;

//Declaring the input GPIOs
unsigned int drdy1_GPIO = 5;
unsigned int drdy2_GPIO = 6;
unsigned int drdy3_GPIO = 13;
unsigned int drdy4_GPIO = 19;

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

int main()
{
//unsigned int sysfs_fd;
int val1;
int val2;
int val3;
int val4;

//Associating the addreses to the memory registors
sysfs_fd1=&value1;
sysfs_fd2=&value2;
sysfs_fd3=&value3;
sysfs_fd4=&value4;

//Setting GPIOs as output
gpio_export(drdy5_GPIO);
gpio_set_dir(drdy5_GPIO,1);
gpio_set_value(drdy5_GPIO,1);

gpio_export(drdy6_GPIO);
gpio_set_dir(drdy6_GPIO,1);
gpio_set_value(drdy6_GPIO,1);

gpio_export(drdy7_GPIO);
gpio_set_dir(drdy7_GPIO,1);
gpio_set_value(drdy7_GPIO,1);

gpio_export(drdy8_GPIO);
gpio_set_dir(drdy8_GPIO,1);
gpio_set_value(drdy8_GPIO,1);

//Setting GPIOs as input
gpio_export(drdy1_GPIO);
gpio_set_dir(drdy1_GPIO,0);

gpio_export(drdy2_GPIO);
gpio_set_dir(drdy2_GPIO,0);

gpio_export(drdy3_GPIO);
gpio_set_dir(drdy3_GPIO,0);

gpio_export(drdy4_GPIO);
gpio_set_dir(drdy4_GPIO,0);

while(1)
{
//For column 1
gpio_set_value(drdy5_GPIO,1);
gpio_set_value(drdy6_GPIO,0);
gpio_set_value(drdy7_GPIO,0);
gpio_set_value(drdy8_GPIO,0);

val4=gpio_get_value(drdy4_GPIO,sysfs_fd4);
val3=gpio_get_value(drdy3_GPIO,sysfs_fd3);
val2=gpio_get_value(drdy2_GPIO,sysfs_fd2);
val1=gpio_get_value(drdy1_GPIO,sysfs_fd1);

if(*sysfs_fd4==1)
{
cout<<"1"<<endl;
usleep(500000);
}
if(*sysfs_fd3==1)
{
cout<<"4"<<endl;
usleep(500000);
}
if(*sysfs_fd2==1)
{
cout<<"7"<<endl;
usleep(500000);
}
if(*sysfs_fd1==1)
{
cout<<"*"<<endl;
usleep(500000);
}

//For column 2
gpio_set_value(drdy5_GPIO,0);
gpio_set_value(drdy6_GPIO,1);
gpio_set_value(drdy7_GPIO,0);
gpio_set_value(drdy8_GPIO,0);

val4=gpio_get_value(drdy4_GPIO,sysfs_fd4);
val3=gpio_get_value(drdy3_GPIO,sysfs_fd3);
val2=gpio_get_value(drdy2_GPIO,sysfs_fd2);
val1=gpio_get_value(drdy1_GPIO,sysfs_fd1);

if(*sysfs_fd4==1)
{
cout<<"2"<<endl;
usleep(500000);
}
if(*sysfs_fd3==1)
{
cout<<"5"<<endl;
usleep(500000);
}
if(*sysfs_fd2==1)
{
cout<<"8"<<endl;
usleep(500000);
}
if(*sysfs_fd1==1)
{
cout<<"0"<<endl;
usleep(500000);
}

//For column 3
gpio_set_value(drdy5_GPIO,0);
gpio_set_value(drdy6_GPIO,0);
gpio_set_value(drdy7_GPIO,1);
gpio_set_value(drdy8_GPIO,0);

val4=gpio_get_value(drdy4_GPIO,sysfs_fd4);
val3=gpio_get_value(drdy3_GPIO,sysfs_fd3);
val2=gpio_get_value(drdy2_GPIO,sysfs_fd2);
val1=gpio_get_value(drdy1_GPIO,sysfs_fd1);

if(*sysfs_fd4==1)
{
cout<<"3"<<endl;
usleep(500000);
}
if(*sysfs_fd3==1)
{
cout<<"6"<<endl;
usleep(500000);
}
if(*sysfs_fd2==1)
{
cout<<"9"<<endl;
usleep(500000);
}
if(*sysfs_fd1==1)
{
cout<<"#"<<endl;
usleep(500000);
}

//For column 4
gpio_set_value(drdy5_GPIO,0);
gpio_set_value(drdy6_GPIO,0);
gpio_set_value(drdy7_GPIO,0);
gpio_set_value(drdy8_GPIO,1);

val4=gpio_get_value(drdy4_GPIO,sysfs_fd4);
val3=gpio_get_value(drdy3_GPIO,sysfs_fd3);
val2=gpio_get_value(drdy2_GPIO,sysfs_fd2);
val1=gpio_get_value(drdy1_GPIO,sysfs_fd1);

if(*sysfs_fd4==1)
{
cout<<"A"<<endl;
usleep(500000);
}
if(*sysfs_fd3==1)
{
cout<<"B"<<endl;
usleep(500000);
}
if(*sysfs_fd2==1)
{
cout<<"C"<<endl;
usleep(500000);
}
if(*sysfs_fd1==1)
{
cout<<"D"<<endl;
usleep(500000);
}
}
return 0;
}







