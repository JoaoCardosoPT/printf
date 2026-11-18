/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacarva <joacarva@c2r3s4.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:25:00 by joacarva          #+#    #+#             */
/*   Updated: 2026/11/18 18:25:00 by joacarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(uintptr_t num, const char *base)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count = ft_put_hex(num / 16, base);
		if (count < 0)
			return (-1);
	}
	if (ft_print_char(base[num % 16]) < 0)
		return (-1);
	return (count + 1);
}

int	ft_print_hex(uintptr_t num)
{
	return (ft_put_hex(num, "0123456789abcdef"));
}

int	ft_print_hex_upper(unsigned int num)
{
	return (ft_put_hex(num, "0123456789ABCDEF"));
}
