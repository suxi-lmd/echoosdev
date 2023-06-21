#include "uart.h"
#include "io.h"
#include "gpio.h"
#include "timer.h"
#include "debug.h"

void print_boot_info(void);
void test_printf(void);

void main(void)
{
    uart_init();
    print_boot_info();
    test_printf();

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


void test_printf(void)
{
    printf("test printf\n");
    printf("test printf %d\n", 1);
    printf("test printf %d %d\n", 1, 2);
    printf("test printf %d %d %d\n", 1, 2, 3);
    printf("test printf %d %d %d %d\n", 1, 2, 3, 4);
    printf("test printf %d %d %d %d %d\n", 1, 2, 3, 4, 5);
    printf("test printf %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6);
    printf("test printf %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7);
    printf("test printf %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8);
    printf("test printf %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9);
    printf("test printf %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10);
    printf("test printf %d %d %d %d %d %d %d %d %d %d %d\n",
    1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11);
    printf("test printf %d %d %d %d %d %d %d %d %d %d %d %d\n",
    1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11, 12);

    printf("test printf %x\n", 0x12345678);
    printf("test printf %x %x\n", 0x12345678, 0x12345678);
    printf("test printf %x %x %x\n", 0x12345678, 0x12345678, 0x12345678);
    printf("test printf %x %x %x %x\n", 0x12345678, 0x12345678, 0x12345678, 0x12345678);
    printf("test printf %x %x %x %x %x\n", 0x12345678, 0x12345678, 0x12345678, 0x12345678, 0x12345678);
    printf("test printf %x %x %x %x %x %x\n",
    0x12345678, 0x12345678, 0x12345678, 0x12345678,
    0x12345678, 0x12345678);
    printf("test printf %x %x %x %x %x %x %x\n",
    0x12345678, 0x12345678, 0x12345678, 0x12345678,
    0x12345678, 0x12345678, 0x12345678);
    printf("test printf %x %x %x %x %x %x %x %x\n",
    0x12345678, 0x12345678, 0x12345678, 0x12345678,
    0x12345678, 0x12345678, 0x12345678, 0x12345678);
    printf("test printf %x %x %x %x %x %x %x %x %x\n",
    0x12345678, 0x12345678, 0x12345678, 0x12345678,
    0x12345678, 0x12345678, 0x12345678, 0x12345678,
    0x12345678);
    printf("test printf %x %x %x %x %x %x %x %x %x %x\n",
    0x12345678, 0x12345678, 0x12345678, 0x12345678,
    0x12345678, 0x12345678, 0x12345678, 0x12345678,
    0x12345678, 0x12345678);

    printf("test printf %s\n", "test");
    printf("test printf %s %s\n", "test", "test");
    printf("test printf %s %s %s\n", "test", "test", "test");
    printf("test printf %s %s %s %s\n", "test", "test", "test", "test");
    printf("test printf %s %s %s %s %s\n", "test", "test", "test", "test", "test");
    printf("test printf %s %s %s %s %s %s\n", "test", "test", "test", "test", "test", "test");
    printf("test printf %s %s %s %s %s %s %s\n", "test", "test", "test", "test", "test", "test", "test");
    printf("test printf %s %s %s %s %s %s %s %s\n", "test", "test", "test", "test", "test", "test", "test", "test");
    printf("test printf %s %s %s %s %s %s %s %s %s\n", "test", "test", "test", "test", "test", "test", "test", "test", "test");
    printf("test printf %s %s %s %s %s %s %s %s %s %s\n", "test", "test", "test", "test", "test", "test", "test", "test", "test", "test");  

    printf("test printf %c\n", 'a');
    printf("test printf %c %c\n", 'a', 'b');
    printf("test printf %c %c %c\n", 'a', 'b', 'c');
    printf("test printf %c %c %c %c\n", 'a', 'b', 'c', 'd');
    printf("test printf %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e');
    printf("test printf %c %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e', 'f');
    printf("test printf %c %c %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g');
    printf("test printf %c %c %c %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
    printf("test printf %c %c %c %c %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i');
    printf("test printf %c %c %c %c %c %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j');

    printf("test printf %s %d %c %x\n", "test", 1, 'a', 0x12345678);
    printf("test printf %s %d %c %x %s %d %c %x\n", "test", 1, 'a', 0x12345678, "test", 1, 'a', 0x12345678);
    printf("test printf %s %d %c %x %s %d %c %x %s %d %c %x\n", "test", 1, 'a', 0x12345678, "test", 1, 'a', 0x12345678, "test", 1, 'a', 0x12345678);
    printf("test printf %s %d %c %x %s %d %c %x %s %d %c %x %s %d %c %x\n", "test", 1, 'a', 0x12345678, "test", 1, 'a', 0x12345678,
    "test", 1, 'a', 0x12345678, "test", 1, 'a', 0x12345678);
}