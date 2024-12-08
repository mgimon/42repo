/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:24:52 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 20:24:33 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
int	main()
{
	int libcresult;
	int	myresult;
	int test;

	test = 61;
	libcresult = isascii(test);
	myresult = ft_isascii(test);
	printf("The result according to isascii is: %d", libcresult);
	printf("The result according to ft_isascii is: %d", myresult);
	return (0);
}
*/
