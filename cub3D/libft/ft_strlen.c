/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:26:26 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/14 20:26:13 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
int	main()
{
	size_t	libcresult;
	size_t	myresult;
	const char test[] = "Hey";

	libcresult = strlen(test);
	myresult = ft_strlen(test);
	printf("The result according to isalpha is: %zu \n", libcresult);
	printf("The result according to ft_isalpha is: %zu \n", myresult);
	return (0);
}
*/
