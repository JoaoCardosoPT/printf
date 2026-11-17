#include "ft_printf.h"

int ft_print_nbr(int n)
{
    int count;
    long num;
    char c;

    num = n;
    count = 0;
    if (num < 0)
    {
       write(1, "-", 1);
       count++;
       num = -num;
    }

    if (n >= 10)
        count += ft_print_nbr(num / 10); 
    
    c = (num % 10) + '0';
    count += write(1, &c, 1);
    return (count);
}

int ft_print_unsinged(unsigned int n)
{
    int count;

    count = 0;
    if (n >= 10)
        count += ft_print_unsinged(n / 10);
    count += ft_print_char((n % 10) + '0');
    return (count);
}
