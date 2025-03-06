/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:27:00 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/15 16:22:20 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_copy;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	s1_copy = malloc(i + 1);
	if (s1_copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s1_copy[i] = (char)s1[i];
		i++;
	}
	s1_copy[i] = '\0';
	return ((char *)s1_copy);
}
