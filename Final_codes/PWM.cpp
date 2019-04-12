/********************************
* Header File
*********************************/
#include <cmath>

/*************************************************************
* Declaring the GPIO 23 to control the base of TIP 121 
**************************************************************/
unsigned int m_GPIO = 23;

/*********************************************************************************************************************************************************************************
* Pointer function declaration of Motor_PWM which takes in input of frequency and duty cycle and returns the value for Time interval for which GPIO should be set to 1 and 0.
*********************************************************************************************************************************************************************************/
int *Motor_PWM(unsigned int frequency,double duty)
{
static int Timeinterval[2];
Timeinterval[0]=floor((1000000/frequency)*(duty));
Timeinterval[1]=floor((1000000/frequency)*(1-duty));
return Timeinterval;
}

/******************************************
* Main function that calls Motor_PWM 
*******************************************/
int motor_Run()
{
/*********************************
* Exporting GPIO 23
**********************************/
gpio_export(m_GPIO);
/*********************************
* Setting GPIO 23 as Output
**********************************/
gpio_set_dir(m_GPIO,1);
/*********************************
* Setting GPIO 23 as Logic 1
**********************************/
gpio_set_value(m_GPIO,1);

/************************************************
* Setting values of Frequency and Duty Cycle 
*************************************************/
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

/******************************************************************************************************
* Declaring a function that takes in one input of 'time' and runs the motor for 'time' micro seconds
*******************************************************************************************************/
void motor_Run_time(unsigned int time){
gpio_export(m_GPIO);
gpio_set_dir(m_GPIO,1);
gpio_set_value(m_GPIO,1);
usleep(time);
gpio_set_value(m_GPIO,0);
}
