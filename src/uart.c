#include "uart.h"
#include "io.h"
#include "gpio.h"


void uart_init() {
    gpio_set_function(14, GPIO_FUNCTION_ALT0);
    gpio_set_function(15, GPIO_FUNCTION_ALT0);
    gpio_set_pull(14, Pull_Down);
    gpio_set_pull(15, Pull_Down);

    out32(UART_CR, 0); //enable UART1
    out32(UART_IBRD, UART_BAUD(115200));
    out32(UART_FBRD, 3);
    out32(UART_LCRH, (1<<4) | (3<<5));
    out32(UART_IMSC, 0); //8 bits
    out32(UART_CR, 1 | (1<<8) | (1<<9)); //enable Tx, Rx, FIFO
}

static unsigned int uart_isWriteReady() 
{
    unsigned int status;
    in32(UART_FR , &status);
    return status & (1 << 5); //bit 5
}

void uart_putc(unsigned char c)
{
    while (uart_isWriteReady());
    out32(UART_DR, (unsigned int)c);
}

void uart_puts(const char *str)
{    
    while (*str) {
       if (*str == '\n') uart_putc('\r');
       uart_putc(*str++);
    }
}

static unsigned int uart_isReadReady()
{
    unsigned int status;
    in32(UART_FR , &status);
    return status & (1 << 4); //bit 0
}

char uart_getc(void)
{
    char c;
    while (uart_isReadReady());
    in32(UART_DR, (unsigned int *)&c);

    return (c & 0xFF);
}

void uart_gets(char *buf, int buf_size)
{
    int i = 0;
    char c;
    while (i < buf_size - 1) {
        c = uart_getc();
        if (c == '\r') {
            buf[i] = '\0';
            return;
        }
        buf[i++] = c;
    }
    buf[i] = '\0';
}