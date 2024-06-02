/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:18:59 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/21 16:34:02 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_char(int c, int *count)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		(*count)++;
	return (1);
}

int	print_hex(unsigned long num, int *count, char c)
{
	char			*str;
	int				i;

	if (c == 'x')
		str = "0123456789abcdef";
	else if (c == 'X')
		str = "0123456789ABCDEF";
	if (num < 16)
	{
		if ((print_hex_char(str[num], count)) == -1)
			return (-1);
	}
	else
	{
		if ((print_hex(num / 16, count, c)) == -1)
			return (-1);
		i = num % 16;
		if ((print_hex_char(str[i], count)) == -1)
			return (-1);
	}
	return (1);
}
