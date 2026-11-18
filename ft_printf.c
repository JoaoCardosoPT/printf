#include "ft_printf.h"

static int	ft_format(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	if (spec == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	if (spec == 'u')
		return (ft_print_unsinged(va_arg(args, unsigned int)));
	if (spec == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
    if (spec == 'x')
        return (ft_print_hex(va_arg(args, unsigned int))
    if (spec == 'X')
        return (ft_print_hex_upper(va_arg(args, unsigned int))
    if (spec == '%')
		return (write(1, "%", 1));
	return (-1);
}

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
        if (str[i] == '%' && str[i + 1])
		{
			written = ft_format(str[i + 1], args);
			i += 2;
		}
		else
			written = write(1, &str[i++], 1);
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
