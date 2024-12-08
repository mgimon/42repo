/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_18.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:17:32 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/09 20:27:25 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_duplicates(char ***env, int i)
{
	int		j;
	char	*s1;
	char	*s2;

	s1 = give_varname((*env)[i]);
	j = i + 1;
	while ((*env)[j])
	{
		s2 = give_varname((*env)[j]);
		if (s1 && s2 && ft_strcmp(s1, s2) == 0)
		{
			free((*env)[i]);
			(*env)[i] = NULL;
			free(s2);
			break ;
		}
		if (s2)
			free(s2);
		j++;
	}
	if (s1)
		free(s1);
}

char	**copy_non_null_elements(char **env, int size)
{
	char	**new_env;
	int		k;
	int		l;

	new_env = malloc(sizeof(char *) * (size + 1));
	if (!new_env)
		return (NULL);
	k = 0;
	l = 0;
	while (l < size)
	{
		if (env[l] != NULL)
		{
			new_env[k] = env[l];
			k++;
		}
		l++;
	}
	new_env[k] = NULL;
	return (new_env);
}

void	free_and_nullify(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
