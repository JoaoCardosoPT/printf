/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacarva <joacarva@c2r3s4.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:25:00 by joacarva          #+#    #+#             */
/*   Updated: 2026/11/18 18:25:00 by joacarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

# ifdef __APPLE__
#  define FT_NULL_PTR "0x0"
# else
#  define FT_NULL_PTR "(nil)"
# endif

int	ft_printf(const char *str, ...);
int	ft_format(char spec, va_list *args);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_ptr(void *ptr);
int	ft_print_hex(uintptr_t num);
int	ft_print_hex_upper(unsigned int num);

#endif
