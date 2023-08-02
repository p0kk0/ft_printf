/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:45:00 by felsanch          #+#    #+#             */
/*   Updated: 2023/08/02 17:39:44 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_filter(char const letra, va_list args)
{
	int	len;
	int	number;

	len = 0;
	number = 0;
	if (letra == 'c')
		len = len + ft_putchar(va_arg(args, int));
	if (letra == '%')
		len = len + write(1, &letra, 1);
	else if (letra == 's')
		len = len + ft_putstr(va_arg(args, char *));
	else if (letra == 'i' || letra == 'd')
		len = len + ft_putnbr(va_arg(args, int), &number);
	else if (letra == 'u')
		len = len + ft_unsigned(va_arg(args, unsigned int), &number);
	else if (letra == 'x' || letra == 'X')
		len = len + ft_hex(va_arg(args, int), &number, letra);
	else if (letra == 'p')
		len = len + ft_pointer(va_arg (args, unsigned long), &number);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		tam;
	va_list	args;

	i = 0;
	tam = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			tam += ft_filter(str[i], args);
		}
		else
		{
			tam++;
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (tam);
}
