#include "ft_printf.h"

int ft_print_string(char *str)
{
    int count;

    if (!str)
        str = "(null)";
    count = 0;
    while (str[count])
    {
        if (write(1, &str[count], 1) < 0)
            return (-1);
        count++;
    }
    return (count);
}
