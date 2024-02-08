/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:23:06 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 20:09:50 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*byte_s;

	byte_s = (unsigned char *)s;
	i = 0;
	while (i < n && n != 0)
	{
		byte_s[i] = 0;
		i++;
	}
}

/*
int	main(void)
{
	char	array[] = "Hello";
	char	myarray[] = "Hello";
	size_t	n;

	n = 4;
	bzero(array, n);
	ft_bzero(myarray, n);
	printf("The output according to bzero is: %s \n", array);
	printf("The output according to ft_bzero is: %s \n", myarray);
	return (0);
}
*/
