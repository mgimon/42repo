/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:01:37 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/18 21:39:36 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dstchar;
	const char	*srcchar;

	dstchar = dst;
	srcchar = src;
	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < n)
	{
		dstchar[i] = srcchar[i];
		i++;
	}
	return (dst);
}

/*
int	main(void)
{
	char	dst[20];
	char	src[] = "Hello";
	char	mydst[20];
	char	mysrc[] = "Hello";
	size_t	n;

	n = 3;
	memcpy(dst, src, n);
	ft_memcpy(mydst, mysrc, n);
	printf("The result is: %s \n", dst);
	printf("My result is: %s \n", mydst);
	return (0);
}
*/
