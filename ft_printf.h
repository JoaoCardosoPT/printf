#ifndef FT_PRINTF_H 
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int ft_print_char(char c);
int ft_print_string(char *str);
int ft_print_nbr(int n);
int ft_print_unsinged(unsigned int n);
int ft_print_unsinged(unsigned int n);
int ft_printf(const char *str, ...);
    
#endif
