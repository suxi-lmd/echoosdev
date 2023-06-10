#include "io.h"

void mmio_write(long reg, unsigned int val)
{
     *(volatile unsigned int *)reg = val; 
}

unsigned int mmio_read(long reg) 
{ 
    return *(volatile unsigned int *)reg; 
}

void in32bit(unsigned int addr, unsigned int *val)
{
    *val = mmio_read(addr); 
}

void out32bit(unsigned int addr, unsigned int val)
{ 
    mmio_write(addr, val); 
}