/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:32:32 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/19 22:04:33 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*resultado;
	size_t	i;
	size_t	j;

	i = 0;
	if (start >= ft_strlen(s))
	{
		resultado = malloc(1);
		resultado[i] = '\0';
		return (resultado);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	resultado = malloc(len + 1);
	if (resultado == NULL)
		return (NULL);
	j = start;
	while (s[j] != '\0' && i < len)
	{
		resultado[i] = s[j];
		i++;
		j++;
	}
	resultado[i] = '\0';
	return (resultado);
}
