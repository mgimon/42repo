/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_20.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:09:25 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/20 20:34:50 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	process_path_segments(const char *path, char **path_parts)
{
	const char	*part;
	const char	*start;
	int			count;
	int			length;

	part = path;
	count = 0;
	while (*part)
	{
		if (*part == '/')
		{
			part++;
			continue ;
		}
		start = part;
		while (*part && *part != '/')
			part++;
		length = part - start;
		if (length > 0)
		{
			if (psnorminetter(&start, &count, &path_parts, &length) == -1)
				return (-1);
		}
	}
	return (count);
}

// Función para construir el path limpio
void	build_clean_path(char *result, char **path_parts, int count)
{
	char	*current;
	int		i;
	int		length;

	current = result;
	i = 0;
	while (i < count)
	{
		if (i > 0)
		{
			*current = '/';
			current++;
		}
		length = strlen(path_parts[i]);
		memcpy(current, path_parts[i], length);
		current += length;
		free(path_parts[i]);
		i++;
	}
	*current = '\0';
}

void	copy_env_var(char **new_env, char **env, int i)
{
	char	*copy;

	copy = strdup(env[i]);
	new_env[i] = copy;
}

char	*extract_pwd(char *env_var)
{
	if (strncmp(env_var, "PWD=", 4) == 0)
		return (env_var + 4);
	return (NULL);
}

char	*create_new_env_entry(char *new_pwd)
{
	char	*new_env_entry;
	int		len;

	len = strlen(new_pwd) + 5;
	new_env_entry = malloc(len);
	if (new_env_entry)
	{
		strcpy(new_env_entry, "PWD=");
		strcat(new_env_entry, new_pwd);
	}
	return (new_env_entry);
}
