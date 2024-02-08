/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:13:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/15 19:00:10 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
int	main(void)
{
	const char	s[] = "Hhhhh";
	int			c;
	char		*resultado;
	char		*miresultado;

	c = 111; // "o"
	resultado = strchr(s, c);
	miresultado = ft_strchr(s, c);
	printf("El resultado es: %s \n", resultado);
	printf("Mi resultado es: %s \n", miresultado);
	return (0);
}
*/
