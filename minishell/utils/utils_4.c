/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:49:28 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/28 21:08:51 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_exports(t_general *info, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	info->exports = (char **)malloc(sizeof(char *) * (i + 1));
	if (!info->exports)
		return ;
	i = 0;
	while (env[i])
	{
		info->exports[i] = ft_strjoin("declare -x ", env[i]);
		if (!info->exports[i])
			return ;
		i++;
	}
	info->exports[i] = NULL;
}

char	*add_var_equal(char *cmdv1)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc((sizeof(char) * ft_strlen(cmdv1)) + 2);
	while (cmdv1[i])
	{
		result[i] = cmdv1[i];
		i++;
	}
	result[i] = '=';
	i++;
	result[i] = '\0';
	return (result);
}

char	**remove_env_line(t_section *current, int line)
{
	int		i;
	int		j;
	char	**new_env;

	initialize_ij(&i, &j);
	new_env = (char **)malloc(count_lines(current->info->env) * sizeof(char *));
	if (ft_strncmp(current->info->env[line], "PATH=", 5) == 0)
		current->info->null_paths = 1;
	while (current->info->env[i])
	{
		if (i != line)
		{
			new_env[j] = ft_strdup(current->info->env[i]);
			if (!new_env[j])
			{
				while (j > 0)
					free(new_env[--j]);
				free(new_env);
				return (current->info->env);
			}
			j++;
		}
		i++;
	}
	return (new_env[j] = NULL, new_env);
}

int	is_directory(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == 0)
	{
		if (S_ISDIR(st.st_mode))
			return (1);
	}
	return (0);
}

char	*ft_getenv(const char *name, char **env)
{
	char	prefix[256];
	size_t	name_len;
	char	**current;

	if (name == NULL || env == NULL)
		return (NULL);
	name_len = ft_strlen(name);
	if (name_len + 1 >= sizeof(prefix))
		return (NULL);
	ft_memcpy(prefix, name, name_len);
	prefix[name_len] = '=';
	prefix[name_len + 1] = '\0';
	current = env;
	while (*current != NULL)
	{
		if (ft_strncmp(*current, prefix, name_len + 1) == 0)
			return (*current + name_len + 1);
		current++;
	}
	return (NULL);
}
