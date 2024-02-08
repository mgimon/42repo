/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:21:53 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/05 15:50:23 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arg_counter(char const *s, char c)
{
	size_t	i;
	size_t	args;

	i = 0;
	args = 0;
	if (s[i] != '\0')
	{
		args++;
		while (s[i] != '\0')
		{
			if ((char)s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
				args++;
			i++;
		}
	}
	return (args);
}

static size_t	arg_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((char)s[i] != c && (char)s[i] != '\0')
		i++;
	return (i);
}

static char	**free_memory(char **result, size_t i)
{
	if (result != NULL)
	{
		while (i > 0)
			free(result[--i]);
		free(result);
	}
	return (NULL);
}

static void	delimiter_runner(char const **s, char c)
{
	while ((char)**s == c && c != '\0')
		(*s)++;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	delimiter_runner(&s, c);
	result = (char **)malloc((arg_counter(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (free_memory(result, 0));
	i = 0;
	while (*s != '\0')
	{
		while ((char)*s == c)
			s++;
		result[i] = (char *)malloc((arg_len(s, c) + 1) * sizeof(char));
		if (result[i] == NULL)
			return (free_memory(result, i));
		ft_strlcpy(result[i], s, arg_len(s, c) + 1);
		s = s + arg_len(s, c);
		i++;
		delimiter_runner(&s, c);
	}
	result[i] = NULL;
	return (result);
}
/*
int	main(void)
{
	char const	*s;
	char		c;
	char		**result;
	int			i;

	i = 0;
	s = "xxxxxHelloxworldxxxxthisxisxanxarrayxxx";
	c = '\0';
	result = ft_split(s, c);
	while (result[i] != NULL)
	{
		printf("%s \n", result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/
