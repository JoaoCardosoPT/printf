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
            written= ft_print_char((char)va_arg(args, int));
            i += 2;
        }
        else
        {
            write(1, &str[i], 1);
            i++;
        }
        if (written < 0)
        {
            count = -1;
            return ;
        }
    }
    // acaba a leitura
    va_end(args);
    return(count);    
}

int main(void) 
{
    const char *str = "ola";

    ft_printf(str);
}