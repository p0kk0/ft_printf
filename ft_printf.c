/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:45:00 by felsanch          #+#    #+#             */
/*   Updated: 2023/07/24 20:26:17 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

char	*ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (0);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (0);
}

int	ft_unsigned(unsigned int num)
{
	if (num > 9)
	{
		ft_unsigned(num / 10);
		ft_unsigned(num % 10);
	}
	else
	{
		ft_putchar(num + '0');
	}
	return (0);
}

// char	*ft_hex(int num)
// {
// 	//1º dividimos el numero que entra entre 16 y guardamos el cociente y el resto
// 	//2º si el cociente es divisible entre 16, seguimos dividiento
// 	int restos;

// 	restos = 0;
// 	while (num > 15)
// 	{
// 		num = num % 16;
		 
// 	}
	
// }

int	ft_filter(char const letra, va_list args)
{
	int	len;

	len = 0;
	if (letra == 'c')
		len = len + ft_putchar(va_arg(args, int));
	if (letra == '%')
		len = len + write(1, &letra, 1);
	else if (letra == 's')
		len = len + ft_putstr(va_arg(args, char *));
	else if (letra == 'i' || letra == 'd')
		len = len + ft_putnbr(va_arg(args, int));
	else if (letra == 'u')
		len = len + ft_unsigned(va_arg(args, unsigned int));
	// else if (letra == 'x')
	// 	ft_hex(va_arg(args, int));
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i; //Recorre toda la entrada. Lo usamos para buscar el inicio de una cadena de formato (%)
	int		tam; //Guardamos el tamaño de lo que se va a imprimir
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
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (tam);
}

int	main(void)
{
	int num = 719;
	
	//printf ("%x\n", num);
	//printf("%% %% .Hey\n");
	//printf ("%d\n", printf("hola"));
	//printf ("%d\n", printf("hasta luego"));
	printf ("%d\n", printf("a"));
	printf ("%d\n", printf("abcde\n"));

	//ft_printf ("%x\n", num);
	//ft_printf("%% %% .Hey\n");
	//ft_printf ("%d\n", ft_printf("hola"));
	//ft_printf ("%d\n", ft_printf("hasta luego"));
	ft_printf("%d\n", ft_printf("a"));
	printf ("%d\n", printf("abcde\n"));

	
	return (0);
}
