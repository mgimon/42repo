/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:18:01 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/17 21:58:04 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*chardst;
	const unsigned char	*charsrc;

	chardst = dst;
	charsrc = src;
	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	if (chardst < charsrc)
		ft_memcpy(chardst, charsrc, len);
	else if (chardst > charsrc)
	{
		i = len;
		while (i > 0)
		{
			i--;
			chardst[i] = charsrc[i];
		}
	}
	return (dst);
}

/*
int	main(void)
{
	char	dst[] = "Hi there ";
	char	src[] = "how are you doing";
	char	mydst[] = "Hi there ";
	char	mysrc[] = "how are you doing";
	size_t	len;

	len = 5;
	memmove(dst, src, len);
	ft_memmove(mydst, mysrc, len);
	printf("The result is: %s \n", dst);
	printf("My result is: %s \n", mydst);
	return (0);
}
*/
