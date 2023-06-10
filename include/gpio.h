#ifndef	_GPIO_H
#define	_GPIO_H

#include "io.h"

enum {
    GPIO_BASE = PERIPHERAL_BASE + 0x200000,
    GPFSEL0 = GPIO_BASE + 0x000000,
    GPFSEL1 = GPIO_BASE + 0x000004,
    GPFSEL2 = GPIO_BASE + 0x000008,
    GPFSEL3 = GPIO_BASE + 0x00000C,
    GPFSEL4 = GPIO_BASE + 0x000010,
    GPFSEL5 = GPIO_BASE + 0x000014,
    GPSET0  = GPIO_BASE + 0x00001C,
    GPSET1  = GPIO_BASE + 0x000020,
    GPCLR0  = GPIO_BASE + 0x000028,
    GPCLR1  = GPIO_BASE + 0x00002C,
    GPLEV0  = GPIO_BASE + 0x000034,
    GPLEV1  = GPIO_BASE + 0x000038,
    GPEDS0  = GPIO_BASE + 0x000040,
    GPEDS1  = GPIO_BASE + 0x000044,
    GPREN0  = GPIO_BASE + 0x00004C,
    GPREN1  = GPIO_BASE + 0x000050,
    GPFEN0  = GPIO_BASE + 0x000058,
    GPFEN1  = GPIO_BASE + 0x00005C,
    GPHEN0  = GPIO_BASE + 0x000064,
    GPHEN1  = GPIO_BASE + 0x000068,
    GPLEN0  = GPIO_BASE + 0x000070,
    GPLEN1  = GPIO_BASE + 0x000074,
    GPAREN0 = GPIO_BASE + 0x00007C,
    GPAREN1 = GPIO_BASE + 0x000080,
    GPAFEN0 = GPIO_BASE + 0x000088,
    GPAFEN1 = GPIO_BASE + 0x00008C,
    GPIO_PUP_PDN_CNTRL_REG0 = GPIO_BASE + 0x0000E4,
    GPIO_PUP_PDN_CNTRL_REG1 = GPIO_BASE + 0x0000E8,
    GPIO_PUP_PDN_CNTRL_REG2 = GPIO_BASE + 0x0000EC,
    GPIO_PUP_PDN_CNTRL_REG3 = GPIO_BASE + 0x0000F0
};

enum {
    GPIO_FUNCTION_IN   = 0,
    GPIO_FUNCTION_OUT  = 1,
    GPIO_FUNCTION_ALT0 = 4,
    GPIO_FUNCTION_ALT1 = 5,
    GPIO_FUNCTION_ALT2 = 6,
    GPIO_FUNCTION_ALT3 = 7,
    GPIO_FUNCTION_ALT4 = 3,
    GPIO_FUNCTION_ALT5 = 2,
};

enum {
    Pull_None = 0,
    Pull_Up   = 1,
    Pull_Down = 2,
};

enum {
    GPIO_LOW  = 0,
    GPIO_HIGH = 1,
};


unsigned int gpio_read(unsigned int pin_number);
unsigned int gpio_write(unsigned int pin_number, unsigned int value);
unsigned int gpio_set_pull(unsigned int pin_number, unsigned int value);
unsigned int gpio_set_function(unsigned int pin_number, unsigned int value);

#endif  /*_GPIO_H */
