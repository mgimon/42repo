/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:24:29 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 20:40:41 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
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

	test = 132;
	libcresult = isalpha(test);
	myresult = ft_isalpha(test);
	printf("The result according to isalpha is: %d", libcresult);
	printf("The result according to ft_isalpha is: %d", myresult);
	return (0);
}
*/
