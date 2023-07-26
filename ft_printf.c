/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:45:00 by felsanch          #+#    #+#             */
/*   Updated: 2023/07/26 21:11:00 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <limits.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

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

 	//1º dividimos el numero que entra entre 16 y guardamos el cociente y el resto
	//2º si el cociente es divisible entre 16, seguimos dividiento
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
	int		i; //Recorre toda la entrada. Lo usamos para buscar el inicio de una cadena de formato (%)
	int		tam; //Guardamos el número de caracteres que imprimimos, es lo que devuelve la función printf
	va_list	args; //Declaracion de variable (args) como tipo va_list, que contiene la información para trabajar con argumentos variádicos
	
	i = 0;
	tam = 0;
	va_start(args, str); //Iniciamos (con la función va_start) nuestra variable (args) en la lista de argumentos (str)
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

// int	main(void)
// {
// 	//long	num = –2147483647;
// 	//char *str = "trambolico";
// 	// char	*str = "Hola me llamo Esteban";
// 	//printf ("%x\n", num);
// 	//printf("%% %% .Hey\n");
// 	//printf ("%d\n", printf("hola"));
// 	//printf ("%d\n", printf("hasta luego"));
// 	// printf ("%d\n", printf("a"));
// 	// printf ("%d\n\n", printf("abcde\n"));

// 	//ft_printf ("%x\n", num);
// 	//ft_printf("%% %% .Hey\n");
// 	//ft_printf ("%d\n", ft_printf("hola"));
// 	//ft_printf ("%d\n", ft_printf("hasta luego"));
// 	// ft_printf("%d\n", ft_printf("a"));
// 	// ft_printf ("%d\n", ft_printf("abcde\n"));
	
// 	printf("%d\n", printf("%d\n", INT_MIN));

// 	ft_printf("%d\n", ft_printf("%d\n", INT_MIN));
// 	return (0);
// }
