#include "debug.h"
#include "uart.h"

typedef char * va_list;  

#ifdef CONFIG_HOST_DARWIN
#define _INTSIZEOF(n)  ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap,v) (ap = (va_list)&v - (7 * _INTSIZEOF(v)))
#define va_arg(ap,t)   (*(t *)((ap += (2 * _INTSIZEOF(t))) - (2 * _INTSIZEOF(t))))
#define va_end(ap)     ( ap = (va_list)0 )
#else // CONFIG_HOST_LINUX
#define _INTSIZEOF(n)  ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap,v) (ap = (va_list)&v - (7 * _INTSIZEOF(v)))
#define va_arg(ap,t)   (*(t *)((ap += (2 * _INTSIZEOF(t))) - (2 * _INTSIZEOF(t))))
#define va_end(ap)     ( ap = (va_list)0 )
#endif

char num_tab[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','a','b','c','d','e','f'};


void putnum(long num, int base, int flag)
{
    unsigned long m;
    char buf[30];

    char *s = buf + sizeof(buf);
    *--s = '\0';

    if(num < 0 && flag == 1) m = -num;
    else m = (unsigned long)num;

    do{
       *--s = num_tab[m % base];
       m /= base;
    }while(m != 0);

    if(num < 0 && flag == 1) *--s = '-';
    
    uart_puts(s);
}


static int vprintf(const char *fmt, va_list ap)
{
    for(; *fmt != '\0'; fmt++)
    {
        if(*fmt != '%'){
            if (*fmt == '\n') uart_putc('\r');
            uart_putc(*fmt);
            continue;      /*终止本次for循环，即本次循环执行到这里不再往下执行，开始下一次for循环*/
        }

        fmt++;
        switch(*fmt){
        case 'd': putnum(va_arg(ap, int), 10, 1);break;
        case 'o': putnum(va_arg(ap, unsigned int), 8, 0); break;
        case 'u': putnum(va_arg(ap, unsigned int), 10, 0); break;
        case 'x': putnum(va_arg(ap, unsigned int), 16, 0); break;
        case 'c': uart_putc(va_arg(ap, int)); break;
        case 's': uart_puts((char *)va_arg(ap,int)); break;
        default:
            uart_putc(*fmt);
            break;
        }
    }
    return 0;
}

void printf(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}