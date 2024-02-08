/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:34:04 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 20:27:12 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	byte_c;
	int				int_c;

	if (c >= 97 && c <= 122)
		return (c);
	else if (c >= 65 && c <= 90)
	{
		byte_c = (unsigned char)c + 32;
		int_c = (int)byte_c;
		return (int_c);
	}
	else
		return (c);
}

/*
int	main(void)
{
	int	c;

	c = 'a';
	printf("The char according to tolower is: %d \n", tolower(c));
	printf("The char according to ft_tolower is: %d \n", ft_tolower(c));
	return (0);
}
*/
