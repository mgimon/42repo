/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:25:13 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 20:24:54 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*
int	main()
{
	int libcresult;
	int	myresult;
	int	test;

	test = 48;
	libcresult = isdigit(test);
	myresult = ft_isdigit(test);
	printf("The result according to isdigit is: %d", libcresult);
	printf("The result according to ft_isdigit is: %d", myresult);
	return (0);
}
*/
