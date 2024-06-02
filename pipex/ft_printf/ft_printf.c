/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:47:33 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/28 22:36:55 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	handle_others(char const *fmt, va_list arg, int *count, int *i)
{
	if (*fmt == 'c')
		*i = print_char(arg, count);
	else if (*fmt == 's')
		*i = print_string(arg, count);
	else if (*fmt == 'p')
		*i = print_pointer(arg, count);
	else if (*fmt == 'i' || *fmt == 'd')
		*i = print_integer(arg, count);
	else if (*fmt == 'u')
		*i = print_unsigned(arg, count);
	else if (*fmt == '%')
		*i = print_percent(count);
	else if (*fmt == '\0')
		*i = 1;
	else
		*i = -1;
}

static int	handle_cspdiux(char const *fmt, va_list arg, int *count)
{
	int				i;
	unsigned long	num;

	i = 0;
	num = 0;
	if (*fmt == 'x' || *fmt == 'X')
	{
		num = (unsigned int)va_arg(arg, unsigned int);
		i = print_hex(num, count, *fmt);
	}
	else
		handle_others(fmt, arg, count, &i);
	return (i);
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
			if (handle_cspdiux(fmt, arg, &count) == -1)
				return (-1);
		}
		else
		{
			if (write(1, fmt, 1) == -1)
				return (-1);
			count++;
		}
		if (*fmt != '\0')
			fmt++;
	}
	va_end(arg);
	return (count);
}
/*
int	main(void)
{
	int		i;
	int		j;

	i = ft_printf("%x", 254);
	printf("%s \n", (char *)NULL); // mi count
	ft_printf("%d ,, %s \n", i, (char *)NULL);
	//j = printf("%x", 254);
	//printf("%s \n", () ); // printf count`
	return (0);
}*/
