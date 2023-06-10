#include "gpio.h"
#include "io.h"

// unsigned int gpio_set     (unsigned int pin_number, unsigned int value) { return gpio_call(pin_number, value, GPSET0, 1, GPIO_MAX_PIN); }
// unsigned int gpio_clear   (unsigned int pin_number, unsigned int value) { return gpio_call(pin_number, value, GPCLR0, 1, GPIO_MAX_PIN); }
// unsigned int gpio_pull    (unsigned int pin_number, unsigned int value) { return gpio_call(pin_number, value, GPIO_PUP_PDN_CNTRL_REG0, 2, GPIO_MAX_PIN); }
// unsigned int gpio_function(unsigned int pin_number, unsigned int value) { return gpio_call(pin_number, value, GPFSEL0, 3, GPIO_MAX_PIN); }


// unsigned int gpio_call(unsigned int pin_number, unsigned int value, unsigned int base, unsigned int field_size, unsigned int field_max) {
//     unsigned int field_mask = (1 << field_size) - 1;
  
//     if (pin_number > field_max) return 0;
//     if (value > field_mask) return 0; 

//     unsigned int num_fields = 32 / field_size;
//     unsigned int reg = base + ((pin_number / num_fields) * 4);
//     unsigned int shift = (pin_number % num_fields) * field_size;

//     unsigned int curval;
//     in32bit(reg , &curval);
//     curval &= ~(field_mask << shift);
//     curval |= value << shift;
//     out32bit(reg, curval);

//     return 1;
// }

unsigned int gpio_read(unsigned int pin_number)
{
    unsigned int value;
    unsigned int shift = (pin_number % 32);
    unsigned int reg = GPLEV0 + (pin_number / 32 * 4);
    in32bit(reg, &value);
    return (value >> shift) & 0x1;
}

unsigned int gpio_write(unsigned int pin_number, unsigned int value)
{
    unsigned int reg;
    unsigned int shift = (pin_number % 32);
    if (value == 0){
        reg = GPCLR0 + (pin_number / 32 * 4);
    } else {
        reg = GPSET0 + (pin_number / 32 * 4);
    }
    out32bit(reg, 1 << shift);
    
    return 0;
}

unsigned int gpio_set_pull(unsigned int pin_number, unsigned int value)
{
    unsigned int reg = GPIO_PUP_PDN_CNTRL_REG0 + (pin_number / (32 / 2) * 4);
    unsigned int shift = pin_number % (32 / 2);
    unsigned int curval;
    in32bit(reg, &curval);
    curval &= ~(0x3 << shift);
    curval |= value << shift;
    out32bit(reg, curval);

    return 0;
}

unsigned int gpio_set_function(unsigned int pin_number, unsigned int value)
{
    unsigned int reg = GPIO_PUP_PDN_CNTRL_REG0 + (pin_number / (32 / 3) * 4);
    unsigned int shift = pin_number % (32 / 3);
    unsigned int curval;
    in32bit(reg, &curval);
    curval &= ~(0x7 << shift);
    curval |= value << shift;
    out32bit(reg, curval);

    return 0;
}