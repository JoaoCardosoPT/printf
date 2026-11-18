/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacarva <joacarva@c2r3s4.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:25:00 by joacarva          #+#    #+#             */
/*   Updated: 2026/11/18 18:25:00 by joacarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(const char *str, va_list *args)
{
	int	count;
	int	written;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!*str)
				return (-1);
			written = ft_format(*str, args);
		}
		else
			written = ft_print_char(*str);
		if (written < 0 || count > INT_MAX - written)
			return (-1);
		count += written;
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	va_start(args, str);
	count = ft_print_format(str, &args);
	va_end(args);
	return (count);
}
