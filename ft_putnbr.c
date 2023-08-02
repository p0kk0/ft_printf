/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:38:43 by felsanch          #+#    #+#             */
/*   Updated: 2023/08/02 17:40:54 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *number)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * (-1);
		*number += 1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, number);
		ft_putnbr(nbr % 10, number);
	}
	else
	{
		ft_putchar(nbr + '0');
		*number += 1;
	}
	return (*number);
}

int	ft_unsigned(unsigned int num, int *number)
{
	if (num > 9)
	{
		ft_unsigned(num / 10, number);
		ft_unsigned(num % 10, number);
	}
	else
	{
		ft_putchar(num + '0');
		*number += 1;
	}
	return (*number);
}
