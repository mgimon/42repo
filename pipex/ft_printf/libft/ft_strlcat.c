/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:25:32 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 21:50:10 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	mystrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		value;

	if (dstsize == 0)
		return (mystrlen(src));
	else if (dstsize < mystrlen(dst))
		value = mystrlen(src) + dstsize;
	else
		value = mystrlen(src) + mystrlen(dst);
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (value);
}

/*
int	main(void)
{
	char	dst[20] = "Hello";
	char	src[] = " World";
	char	mydst[20] = "Hello";
	char	mysrc[] = " World";
	size_t	dstsize;

	dstsize = 8;
	strlcat(dst, src, dstsize);
	ft_strlcat(mydst, mysrc, dstsize);
	printf("The output according to strlcat is: %s \n", dst);
	printf("The output according to ft_strlcat is: %s \n", mydst);
	return (0);
}
*/
