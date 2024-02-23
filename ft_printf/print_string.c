/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:11:05 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/16 16:29:01 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list arg, int *count)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		*count += 6;
		return (*count);
	}
	if (*s == '\0')
		return (1);
	while (*s)
	{
		if (write(1, &(*s), 1) == -1)
			return (-1);
		(*count)++;
		s++;
	}
	return (*count);
}
