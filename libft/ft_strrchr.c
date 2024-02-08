/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:04:29 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/15 19:18:05 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*beggining;

	beggining = s;
	while (*s != '\0')
	{
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	while (s >= beggining)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	s[] = "Hola";
	int			c;
	char		*resultado;
	char		*miresultado;

	c = 111; // "o"
	resultado = strrchr(s, c);
	miresultado = ft_strrchr(s, c);
	printf("El resultado es: %s \n", resultado);
	printf("Mi resultado es: %s \n", miresultado);
	return (0);
}
*/
