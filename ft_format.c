/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacarva <joacarva@c2r3s4.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:25:00 by joacarva          #+#    #+#             */
/*   Updated: 2026/11/18 18:25:00 by joacarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_print_char((char)va_arg(*args, int)));
	if (spec == 's')
		return (ft_print_string(va_arg(*args, char *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	if (spec == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	if (spec == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (spec == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int)));
	if (spec == 'X')
		return (ft_print_hex_upper(va_arg(*args, unsigned int)));
	if (spec == '%')
		return (ft_print_char('%'));
	return (-1);
}
