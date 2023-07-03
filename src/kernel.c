#include "uart.h"
#include "io.h"
#include "gpio.h"
#include "timer.h"
#include "debug.h"
#include "mm.h"

void print_boot_info(void);

void main(void)
{
    uart_init();
    print_boot_info();

    while (1) {
		uart_putc(uart_getc());
	}
}

void print_boot_info(void)
{
    uart_puts("\n");
    uart_puts("---------------------\n");
    uart_puts("echoos!\n");
    uart_puts("Hello world!\n");
    uart_puts("---------------------\n");
}