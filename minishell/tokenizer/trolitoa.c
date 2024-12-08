/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trolitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:32:34 by albealva          #+#    #+#             */
/*   Updated: 2024/11/17 20:00:00 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	digit_counter(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	validate_sign(int *n, int *i, char **buffer)
{
	if (*n < 0)
	{
		*buffer[*i] = '-';
		*n = -(*n);
		(*i)++;
	}
}

static char	*inverse(char *buffer)
{
	size_t	j;
	size_t	i;
	char	temp;
	char	*result;

	i = ft_strlen(buffer) - 1;
	result = (char *)buffer;
	j = 0;
	if (buffer[j] == '-')
		j++;
	while (j < i)
	{
		temp = result[j];
		result[j] = result[i];
		result[i] = temp;
		j++;
		i--;
	}
	return (result);
}

char	*trolft_itoa(int n, t_general *info)
{
	char	*buffer;
	char	*result;
	int		digits;
	int		i;

	i = 0;
	digits = digit_counter(n);
	if (n == 0)
		return (trolft_strdup("0", info));
	if (n == -2147483648)
		return (trolft_strdup("-2147483648", info));
	buffer = my_malloc(info, digits + 1);
	if (buffer == NULL)
		return (NULL);
	validate_sign(&n, &i, &buffer);
	while (n > 0)
	{
		buffer[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	buffer[i] = '\0';
	result = trolft_strdup(inverse(buffer), info);
	return (result);
}
