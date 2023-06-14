#ifndef	_UART_H
#define	_UART_H

#include "io.h"

enum {
    AUX_BASE        = PERIPHERAL_BASE + 0x215000,
    AUX_IRQ         = AUX_BASE + 0x00, // Auxiliary Interrupt status
    AUX_ENABLES     = AUX_BASE + 0x04, // Auxiliary enables
    AUX_MU_IO_REG   = AUX_BASE + 0x40, // Mini Uart I/O Data
    AUX_MU_IER_REG  = AUX_BASE + 0x44, // Mini Uart Interrupt Enable
    AUX_MU_IIR_REG  = AUX_BASE + 0x48, // Mini Uart Interrupt Identify
    AUX_MU_LCR_REG  = AUX_BASE + 0x4C, // Mini Uart Line Control
    AUX_MU_MCR_REG  = AUX_BASE + 0x50, // Mini Uart Modem Control
    AUX_MU_LSR_REG  = AUX_BASE + 0x54, // Mini Uart Line Status
    AUX_MU_MSR_REG  = AUX_BASE + 0x58, // Mini Uart Modem Status
    AUX_MU_SCRATCH  = AUX_BASE + 0x5C, // Mini Uart Scratch
    AUX_MU_CNTL_REG = AUX_BASE + 0x60, // Mini Uart Extra Control
    AUX_MU_STAT_REG = AUX_BASE + 0x64, // Mini Uart Extra Status
    AUX_MU_BAUD_REG = AUX_BASE + 0x68, // Mini Uart Baudrate
    AUX_UART_CLOCK  = 500000000,       // Mini Uart clock
    UART_MAX_QUEUE  = 16 * 1024,       // UART FIFO size
};

#define AUX_MU_BAUD(baud) ((AUX_UART_CLOCK/(baud*8))-1)

void uart_init(void);

void uart_putc(unsigned char c);
void uart_puts(const char *str);
char uart_getc(void);
void uart_gets(char *buf, int buf_size);
void printf(const char *format, ...);


#endif  /*_UART_H */
