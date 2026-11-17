#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int count;
    int written;

    i = 0;
    count = 0;
    // prepara a leitura de arguments
    va_start(args, str);
    while(str[i] != '\0')
    {
        if (str[i] == '%' && str[i + 1] == 'c')
        {
            // vai buscar o argument em int e transforma em char
            written = ft_print_char((char)va_arg(args, int));
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == 's')
        {
            written = ft_print_string(va_arg(args, char *));
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == 'd')
        {
            written = ft_print_nbr(va_arg(args, int));
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == '%')
        {
            written = write(1, "%", 1);
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == 'u')
        {
            written = ft_print_unsinged(va_arg(args, unsigned int));
            i += 2;
        }
        else
        {
            written = write(1, &str[i], 1);
            i++;
        }

        if (written < 0)
        {
            va_end(args);
            return (-1);
        }

        count += written;
    }
    // acaba a leitura
    va_end(args);
    return(count);    
}
