/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:32:32 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/05 12:17:54 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// verificamos si la longitud solicitada para la substr
// es + que la longitud restante de la str
// a partir de la posicion start.
// Si es asi, ajusto len para que sea =
// a la longitud restante de la cadena

static void	len_adjust(size_t *len, char const *s, unsigned int start)
{
	if (*len > ft_strlen(s + start))
		*len = ft_strlen(s + start);
}

static void	index_move(size_t *i, size_t *j)
{
	(*i)++;
	(*j)++;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*resultado;
	size_t	i;
	size_t	j;

	i = 0;
	if (start >= ft_strlen(s))
	{
		resultado = malloc(1);
		if (resultado == NULL)
			return (NULL);
		resultado[i] = '\0';
		return (resultado);
	}
	len_adjust(&len, s, start);
	resultado = malloc(len + 1);
	if (resultado == NULL)
		return (NULL);
	j = start;
	while (s[j] != '\0' && i < len)
	{
		resultado[i] = s[j];
		index_move(&i, &j);
	}
	resultado[i] = '\0';
	return (resultado);
}
