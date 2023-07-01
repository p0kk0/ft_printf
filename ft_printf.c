/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:45:00 by felsanch          #+#    #+#             */
/*   Updated: 2023/07/01 11:23:30 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1,&c, 1);
	return (0);
}

int	ft_filter(char const str, va_list args)
{
	if (str == 'c')
	{
		ft_putchar(va_arg(args, int));
	}
/*
	else if (c == 's')
	{
		ft_str(va_arg(args, int));
	}
	else if (c == 'p')

	else if (c == 'd')

	else if (c == 'i')

	else if (c == 'u')

	else if (c == 'x')

	else if (c == 'X')
	
	else if (c == '%')
	*/
return (0);
}

int	ft_printf(char const *str, ...)
{
	int	c; //Recorre el string
	va_list	args; //Declaracion de variable contiene los argumentos variadicos

	va_start(args, str);
	c = 0;
	while (str[c])
	{
		if (str[c] == '%')
		{
			c++;
			ft_filter(str[c], args);
		}
		else
			ft_putchar(str[c]);
		c++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	/*int a = 'donde';*/
	printf("donde\n");
	ft_printf("donde");
	return (0);
}

/*
	int num = 12; 
	int num2 = 12345; 
	printf("%d\n",num2); 
	printf("%5d\n",num); Imprime un numero de 5 digitos en el que a la derecha 
	está num y hay tantos 0 
	a la izquierda como espacios libres queden hasta hacer 5 digitos
	return 0;
*/