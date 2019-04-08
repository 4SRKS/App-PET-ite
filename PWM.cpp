//#include <stdint.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <fcntl.h>
//#include <sys/ioctl.h>
//#include <linux/types.h>
//#include <linux/spi/spidev.h>
//#include "gpio-sysfs.h"
//#include "gpio-sysfs.cpp"
#include <cmath>
//#include <iostream>
//using namespace std;

unsigned int m_GPIO = 23;

//Function declaration of PWM
int *Motor_PWM(unsigned int frequency,double duty)
{
static int Timeinterval[2];
Timeinterval[0]=floor((1000000/frequency)*(duty));
Timeinterval[1]=floor((1000000/frequency)*(1-duty));
return Timeinterval;
}

int motor_Run()
{
//Setting GPIO 22 as output
gpio_export(m_GPIO);
gpio_set_dir(m_GPIO,1);
gpio_set_value(m_GPIO,1);

unsigned int freq;
freq=1;
double d;
d=0.75;
int *duration;

while(1)
{
duration=Motor_PWM(freq,d);
gpio_set_value(m_GPIO,1);
usleep(*duration);
gpio_set_value(m_GPIO,0);
usleep(*(duration+1));
}
return 0;
}

void motor_Run_time(unsigned int time){
gpio_export(m_GPIO);
gpio_set_dir(m_GPIO,1);
gpio_set_value(m_GPIO,1);
usleep(time);
gpio_set_value(m_GPIO,0);
}

