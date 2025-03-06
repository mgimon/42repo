/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:25:33 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/15 20:06:48 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			if ((unsigned char)s1[i] > (unsigned char)s2[i])
				return (1);
			else
				return (-1);
		}
		else if ((unsigned char)s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char s1[] = "Hola mundo";
	const char s2[] = "Hola mundoquetal";
	size_t	n;
	int	result;
	int	myresult;

	n = 3;
	result = strncmp(s1, s2, n);
	myresult = ft_strncmp(s1, s2, n);
	printf("El resultado es: %d \n", result);
	printf("Mi resultado es: %d \n", myresult);
	return (0);
}
*/
