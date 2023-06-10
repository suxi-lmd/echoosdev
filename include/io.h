#ifndef	_IO_H
#define	_IO_H

//外围总线寄存器基地址
#define PERIPHERAL_BASE 0xFE000000

void mmio_write(long reg, unsigned int val);
unsigned int mmio_read(long reg);

void in32(unsigned int addr, unsigned int *val);
void out32(unsigned int addr, unsigned int val);

#endif  /*_IO_H */
