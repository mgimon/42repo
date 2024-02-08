/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:38:49 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 21:53:57 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize == 0)
	{
		while (src[j] != '\0')
			j++;
		return (j);
	}
	while (i < dstsize - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	return (j);
}

/*
int	main()
{
	char	dst[] = "Hello";
	char	src[] = " World";
	char	mydst[] = "Hello";
	char	mysrc[] = "World";
	size_t	dstsize;

	dstsize = 4;
	strlcpy(dst, src, dstsize);
	ft_strlcpy(mydst, mysrc, dstsize);
	printf("The output according to strlcpy is: %s \n", dst);
	printf("The output according to ft_strlcpy is: %s \n", mydst);
	return (0);
}
*/
