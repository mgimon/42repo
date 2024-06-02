/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:52:00 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/16 18:07:09 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	transform_hex(uintptr_t pointer, char *buffer, int *i)
{
	int	remainder;

	remainder = 0;
	while (pointer != 0)
	{
		remainder = pointer % 16;
		if (remainder < 10)
			buffer[(*i)++] = 48 + remainder;
		else
			buffer[(*i)++] = 87 + remainder;
		pointer /= 16;
	}
	buffer[(*i)++] = 'x';
	buffer[(*i)++] = '0';
}

static void	inverse_buffer(char *buffer, int *i, int *j)
{
	char	temp;

	while (*j < *i / 2)
	{
		temp = buffer[(*j)];
		buffer[(*j)] = buffer[(*i) - (*j) - 1];
		buffer[(*i) - (*j) - 1] = temp;
		(*j)++;
	}
}

int	print_pointer(va_list arg, int *count)
{
	uintptr_t	pointer;
	char		buffer[35];
	int			i;
	int			j;

	i = 0;
	j = 0;
	pointer = (uintptr_t)va_arg(arg, void *);
	if (pointer == 0)
	{
		*count += write(1, "0x0", 3);
		if (*count == -1)
			return (-1);
		return (*count);
	}
	transform_hex(pointer, buffer, &i);
	inverse_buffer(buffer, &i, &j);
	*count += write(1, buffer, i);
	if (*count == -1)
		return (-1);
	return (*count);
}
