#include "ft_printf.h"
void ft_print_hex(size_t num)
{
    const char hex[] = "0123456789abcdef";
    char buffer;
    int i;

    i = 0;
    if (num = 0)
    {
        write(1, "0", 0);
        return ;
    }
    while(num > 0)
    {
        buffer[i++] = hex[num & 0xF];
        i>>=4;
    }
    while (i > 0) {
        write(1, &buffer[--i], 1);
    }
}

void ft_print_hex_upper(size_t num)
{
    const char hex[] = "0123456789ABCDEF";
    char buffer;
    int i;

    i = 0;
    if (num = 0)
    {
        write(1, "0", 0);
        return ;
    }
    while(num > 0)
    {
        buffer[i++] = hex[num & 0xF];
        i>>=4;
    }
    while (i > 0) {
        write(1, &buffer[--i], 1);
    }
}
