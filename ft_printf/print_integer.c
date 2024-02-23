/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:45:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/16 14:46:02 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	free_if_null(char *s_origin, int *count, int *result)
{
	if (write(1, "(null)", 6) != 6)
		free(s_origin);
	else
	{
		*count += 6;
		free(s_origin);
	}
	*result = -1;
}

static void	iterate(char **s, int *count)
{
	(*count)++;
	(*s)++;
}

int	print_integer(va_list arg, int *count)
{
	char	*s;
	char	*s_origin;
	int		result;

	s = ft_itoa(va_arg(arg, int));
	s_origin = s;
	result = 1;
	if (!s || *s == '\0')
	{
		if (!s)
			free_if_null(s_origin, count, &result);
		return (result);
	}
	while (*s)
	{
		if (write(1, &(*s), 1) == -1)
		{
			free(s_origin);
			return (-1);
		}
		iterate(&s, count);
	}
	free(s_origin);
	return (*count);
}
