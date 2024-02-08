/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:50:29 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/16 00:15:12 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((int)(((unsigned char *)s1)[i])
			- ((int)(((unsigned char *)s2)[i])));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = "Hello";
	size_t	n;

	n = 5;
	printf("El resultado es: %d \n", memcmp(s1, s2, n));
	printf("Mi resultado es: %d \n", ft_memcmp(s1, s2, n));
	return (0);
}
*/
