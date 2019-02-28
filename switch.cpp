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

unsigned int drdy1_GPIO = 22;
unsigned int drdy2_GPIO = 17;
unsigned int *sysfs_fd;
unsigned int value;

int main()
{
//unsigned int sysfs_fd;
int readval;
int val;
sysfs_fd=&value;

//Setting GPIO 22 as output
gpio_export(drdy1_GPIO);
gpio_set_dir(drdy1_GPIO,1);
gpio_set_value(drdy1_GPIO,1);

//Setting GPIO 17 as input
gpio_export(drdy2_GPIO);
gpio_set_dir(drdy2_GPIO,0);

while(1)
{
val=gpio_get_value(drdy2_GPIO,sysfs_fd);
//cout<<*sysfs_fd;
if(*sysfs_fd==1)
{
gpio_set_value(drdy1_GPIO,1);
}
else
{
gpio_set_value(drdy1_GPIO,0);
usleep(500000);
gpio_set_value(drdy1_GPIO,1);
usleep(500000);
}
}
return 0;
}
