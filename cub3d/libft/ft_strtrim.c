/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:19:50 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/07/18 14:29:21 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// eliminamos los caracteres finales

static void	trim_end(char const *s1, char const *set, size_t *end)
{
	while (ft_strchr(set, s1[(*end)]))
		(*end)--;
}

static void	position_setter(char const *s1, size_t *start, size_t *end)
{
	*start = 0;
	*end = ft_strlen(s1) - 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	position_setter(s1, &start, &end);
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	trim_end(s1, set, &end);
	result = malloc(end - start + 2);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[start], end - start + 2);
	return (result);
}
/*
____aa__bbb___

__
*/
