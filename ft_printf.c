#include "ft_printf.h"

int ft_printf(const char *str)
{
    int i;

    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (0);
}

int main(void) 
{
    const char *str = "ola";

    ft_printf(str);
}