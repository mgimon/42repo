/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:24:07 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 20:23:56 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
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
	libcresult = isalnum(test);
	myresult = ft_isalnum(test);
	printf("The result according to isalnum is: %d \n", libcresult);
	printf("The result according to ft_isalnum is: %d", myresult);
	return (0);
}
*/
