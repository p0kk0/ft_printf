/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:36:08 by felsanch          #+#    #+#             */
/*   Updated: 2023/08/02 17:42:24 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(int num, int *number, char const letra)
{
	unsigned int	nbr;
	char			*str;
	char			*str2;

	nbr = (unsigned int)num;
	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	if (nbr > 15)
	{
		ft_hex(nbr / 16, number, letra);
		ft_hex(nbr % 16, number, letra);
	}
	else
	{
		if (letra == 'x')
			ft_putchar(str[nbr]);
		else
			ft_putchar(str2[nbr]);
		*number += 1;
	}
	return (*number);
}

int	ft_pointer(unsigned long num, int *number)
{
	char			*str;

	str = "0123456789abcdef";
	if (*number == 0)
	{
		write(1, "0x", 2);
		*number = *number + 2;
	}
	if (num > 15)
	{
		ft_pointer(num / 16, number);
		ft_pointer(num % 16, number);
	}
	else
	{
		ft_putchar(str[num]);
		*number += 1;
	}	
	return (*number);
}
