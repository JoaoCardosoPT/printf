/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacarva <joacarva@c2r3s4.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:25:00 by joacarva          #+#    #+#             */
/*   Updated: 2026/11/18 18:25:00 by joacarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count = ft_print_unsigned(n / 10);
		if (count < 0)
			return (-1);
	}
	if (ft_print_char((n % 10) + '0') < 0)
		return (-1);
	return (count + 1);
}

int	ft_print_nbr(int n)
{
	unsigned int	num;
	int				count;
	int				written;

	num = (unsigned int)n;
	count = 0;
	if (n < 0)
	{
		if (ft_print_char('-') < 0)
			return (-1);
		count = 1;
		num = 0 - num;
	}
	written = ft_print_unsigned(num);
	if (written < 0)
		return (-1);
	return (count + written);
}
