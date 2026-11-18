#include "ft_printf.h" 

void put_hex(int n)
{
    char *base;

    base = "0123456789abcdef";
    if (n >= 16)
        put_hex(n / 16);
    write(1, &base[n % 16], 1);
}

int ft_print_ptr(void *ptr)
{
    int addr;

    if (!ptr)
    {
        write(1, "(nill)", 5);
        return (5);
    }
    addr = (int)ptr;
}
