/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:44:54 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/19 20:38:54 by mgimon-c         ###   ########.fr       */
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

static char	*unsignedtoa(unsigned int num, char **s)
{
	int				digits;
	unsigned int	temp;
	char			*str;
	char			*ptr;

	digits = 1;
	temp = num;
	while ((temp / 10) != 0)
	{
		digits++;
		temp = temp / 10;
	}
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ptr = str + digits;
	*ptr = '\0';
	while (num)
	{
		*--ptr = '0' + (num % 10);
		num /= 10;
	}
	free(*s);
	*s = str;
	return (*s);
}

static int	unsigner(char **s)
{
	int				n;
	char			*i;
	unsigned int	result;
	unsigned int	absolut;

	i = "hey";
	if (s != NULL && *s != NULL && **s == '-')
	{
		n = ft_atoi(*s);
		absolut = (unsigned int)(-n);
		result = ~absolut + 1;
		i = unsignedtoa(result, &(*s));
	}
	if (i == NULL)
		return (1);
	else
		return (-1);
}

int	print_unsigned(va_list arg, int *count)
{
	char			*s;
	char			*s_origin;
	int				result;

	s = ft_itoa(va_arg(arg, int));
	result = unsigner(&s);
	s_origin = s;
	if (!s || *s == '\0' || result == 1)
	{
		if (!s || result == 1)
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
