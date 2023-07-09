/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:45:00 by felsanch          #+#    #+#             */
/*   Updated: 2023/07/09 19:38:01 by felsanch         ###   ########.fr       */
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

char	*ft_hex(int num)
{
	//1º dividimos el numero que entra entre 16 y guardamos el cociente y el resto
	//2º si el cociente es divisible entre 16, seguimos dividiento
	int restos;

	restos = 0;
	while (num > 15)
	{
		num = num % 16;
		 
	}
	
}

int	ft_filter(char const letra, va_list args)
{
	if (letra == 'c')
		ft_putchar(va_arg(args, int));
	if (letra == '%')
		write(1, &letra, 1);
	else if (letra == 's')
		ft_putstr(va_arg(args, char *));
	else if (letra == 'i' || letra == 'd')
		ft_putnbr(va_arg(args, int));
	else if (letra == 'u')
		ft_unsigned(va_arg(args, unsigned int));
	else if (letra == 'x')
		ft_hex(va_arg(args, int));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		i; //Recorre el total del string
	va_list	args; //Declaracion de variable (args) como tipo va_list, que contiene la información para trabajar con argumentos variádicos

	i = 0;
	va_start(args, str); //Iniciamos (con la función va_start) nuestra variable (args) en la lista de argumentos (str)
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_filter(str[i], args);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	// char a = 'b';
	// printf("El caracter es %c.\n", a);
	// ft_printf("El caracter es %c.\n", a);

	// char *sentence = "kfdjnv618*14%!";
	// printf("%s\n", sentence);
	// ft_printf("%s\n", sentence);

	// int integer = -21474818;
	// printf("%i\n", integer);
	// ft_printf("%i\n", integer);

	// float	i = 3.14;
	// printf("El numero es: %f\n", i);
	// ft_printf("El numero es: %f\n", i);

	// unsigned int num2 = 423292;
	// printf("%u\n", num2);
	// ft_printf("%u\n", num2);

	// printf("%% %% .Hey\n");
	// ft_printf("%% %% .Hey\n");

	
	int	numhex = 719;
	printf("%x\n", numhex);
	//ft_printf("%x\n", numhex);
	return (0);
}
