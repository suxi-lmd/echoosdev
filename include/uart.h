#ifndef	_UART_H
#define	_UART_H

#include "io.h"

enum {
    UART_BASE        = PERIPHERAL_BASE + 0x201000,
    UART_DR          = UART_BASE + 0x00, // Data Register
    UART_RSRECR      = UART_BASE + 0x04, // Receive Status Register / Error Clear Register
    UART_FR          = UART_BASE + 0x18, // Flag Register
    UART_ILPR        = UART_BASE + 0x20, // IrDA Low-power Counter Register
    UART_IBRD        = UART_BASE + 0x24, // Integer Baud Rate Register
    UART_FBRD        = UART_BASE + 0x28, // Fractional Baud Rate Register
    UART_LCRH        = UART_BASE + 0x2C, // Line Control Register
    UART_CR          = UART_BASE + 0x30, // Control Register
    UART_IFLS        = UART_BASE + 0x34, // Interrupt FIFO Level Select Register
    UART_IMSC        = UART_BASE + 0x38, // Interrupt Mask Set Clear Register
    UART_RIS         = UART_BASE + 0x3C, // Raw Interrupt Status Register
    UART_MIS         = UART_BASE + 0x40, // Masked Interrupt Status Register
    UART_ICR         = UART_BASE + 0x44, // Interrupt Clear Register
    UART_DMACR       = UART_BASE + 0x48, // DMA Control Register
    UART_ITCR        = UART_BASE + 0x80, // Test Control Register
    UART_ITIP        = UART_BASE + 0x84, // Integration Test Input Register
    UART_ITOP        = UART_BASE + 0x88, // Integration Test Output Register
    UART_TDR         = UART_BASE + 0x8C, // Test Data Register
    UART_CLOCK       = 48000000,         // UART clock
};
#define UART_BAUD(baud) ((UART_CLOCK/(baud*16))-1)

void uart_init(void);

void uart_putc(unsigned char c);
void uart_puts(const char *str);
char uart_getc(void);
void uart_gets(char *buf, int buf_size);


#endif  /*_UART_H */
