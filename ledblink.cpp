/*
 * AD7705 test program for the Raspberry PI
 *
 * Copyright (c) 2007  MontaVista Software, Inc.
 * Copyright (c) 2007  Anton Vorontsov <avorontsov@ru.mvista.com>
 * Copyright (c) 2013-2018  Bernd Porr <mail@berndporr.me.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * Cross-compile with cross-gcc -I/path/to/cross-kernel/include
 */

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

unsigned int drdy_GPIO = 22;

int main()
{
unsigned int *sysfs_fd;
int readval;
//Setting GPIO 22 as output
gpio_export(drdy_GPIO);
gpio_set_dir(drdy_GPIO,1);
gpio_set_value(drdy_GPIO,1);

while(1)
{
gpio_set_value(drdy_GPIO,1);
usleep(500000);
gpio_set_value(drdy_GPIO,0);
usleep(500000);
}
return 0;
}
