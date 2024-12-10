/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:26:05 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 20:23:02 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*byte_b;

	byte_b = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		byte_b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
int	main()
{
	char	array[10];
	char	myarray[10];
	size_t	len;
	int		c;

	len = 9;
	c = 'A';
	memset(array, c, len);
	ft_memset(myarray, c, len);
	printf("The output according to memset is: %s \n", array);
	printf("The output according to ft_memset is: %s \n", myarray);
	return (0);
}
*/
