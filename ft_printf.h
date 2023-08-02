/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:55:45 by felsanch          #+#    #+#             */
/*   Updated: 2023/08/02 17:45:53 by felsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n, int *number);
int	ft_unsigned(unsigned int num, int *number);
int	ft_hex(int num, int *number, char const letra);
int	ft_pointer(unsigned long num, int *number);
int	ft_filter(char const letra, va_list args);
int	ft_printf(char const *str, ...);

#endif