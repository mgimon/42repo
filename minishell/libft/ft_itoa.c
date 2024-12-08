/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:19:19 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/18 14:30:10 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	char	*buffer;
	char	*result;
	int		digits;
	int		i;

	i = 0;
	digits = digit_counter(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	buffer = malloc(digits + 1);
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
	result = ft_strdup(inverse(buffer));
	free(buffer);
	return (result);
}
/*
int main(void)
{
	int		n;
	char	*string_number;

	n = -1256;
	string_number = ft_itoa(n);
	printf("El resultado es: %s \n", string_number);
	free(string_number);
	return (0);
}
*/
