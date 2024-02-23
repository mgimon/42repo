/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:53:46 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/16 00:15:52 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		i++;
		s++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "bonjour";
	int		c;
	size_t	n;

	c = 98;
	n = 4;
	printf("The result is: %s \n", memchr(s, c, n));
	printf("My result is: %s \n", ft_memchr(s, c, n));
	return (0);
}
*/
