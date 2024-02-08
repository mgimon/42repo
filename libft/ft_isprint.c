/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:25:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 20:25:14 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	libcresult = isprint(test);
	myresult = ft_isprint(test);
	printf("The result according to isprint is: %d", libcresult);
	printf("The result according to ft_isprint is: %d", myresult);
	return (0);
}
*/
