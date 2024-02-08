/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:47:33 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/08 23:12:33 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// pasar count para seguir contando

static int	handle_cspdiux(char const *fmt, va_list arg, int *count)
{
	int	i;

	i = 1;
	if (*fmt == 'c')
	{
		i = print_char(arg, count);
		return (1);
	}
/*	else if (*fmt == 's')
		print_string();
	else if (*fmt == 'p')
		print_void();
	else if (*fmt == 'd')
		print_double();
	else if (*fmt == 'i')
		print_integer();
	else if (*fmt == 'u')
		print_unsigned();
	else if (*fmt == 'x')
		print_hexmin();
	else if (*fmt == 'X')
		print_hexmax();
	else if (*fmt == '%')
		print_percent();*/
	else
	{
		*count = -1;
		return (-1);
	}
	if (i < 0)
		return (-1);
}

int	ft_printf(char const *fmt, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			handle_cspdiux(fmt, arg, &count);
			if (count < 0)
				return (-1);
		}
		else if (write(1, fmt, 1) == -1)
			return (-1);
		fmt++;
		count++;
	}
	return (count);
}
/*
int	main(void)
{
	int		i;
	int		j;
	char	x;

	x = 'z';
	i = ft_printf("Hola %c %c", x, x);
	printf("%d \n", i); // mi count

	j = printf("Hola %c %c", x, x);
	printf("%d \n", j); // printf count
	return (0);
}*/
