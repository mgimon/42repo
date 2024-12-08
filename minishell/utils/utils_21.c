/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_21.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:13:57 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/14 21:02:50 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Función principal
char	*clean_path(const char *path)
{
	char	**path_parts;
	char	*result;
	int		count;

	path_parts = allocate_path_parts();
	if (!path_parts)
		return (NULL);
	result = allocate_result(path);
	if (!result)
	{
		free(path_parts);
		return (NULL);
	}
	count = process_path_segments(path, path_parts);
	if (count == -1)
	{
		free_allocated_parts(path_parts, count, result);
		return (NULL);
	}
	build_clean_path(result, path_parts, count);
	free(path_parts);
	return (result);
}

int	calculate_env_size(char **env)
{
	int	count;

	count = 0;
	while (env[count])
	{
		count++;
	}
	return (count);
}

void	free_and_replace_env(t_section *current, char **new_env)
{
	matrix_free(current->info->env);
	current->info->env = new_env;
}

void	process_env_var(char **new_env, char **env, int i)
{
	char	*pwd;
	char	*new_pwd;
	char	*new_env_entry;

	pwd = extract_pwd(env[i]);
	if (pwd && strstr(pwd, ".."))
	{
		new_pwd = clean_path(pwd);
		if (new_pwd)
		{
			new_env_entry = create_new_env_entry(new_pwd);
			if (new_env_entry)
				new_env[i] = new_env_entry;
			else
				copy_env_var(new_env, env, i);
			free(new_pwd);
		}
	}
	else
		copy_env_var(new_env, env, i);
}

void	if_clean_complex_route(t_section *current)
{
	char	**env;
	char	**new_env;
	int		i;
	int		env_count;

	env = current->info->env;
	i = 0;
	env_count = calculate_env_size(env);
	new_env = malloc((env_count + 1) * sizeof(char *));
	if (!new_env)
		return ;
	while (env[i])
	{
		process_env_var(new_env, env, i);
		i++;
	}
	new_env[i] = NULL;
	free_and_replace_env(current, new_env);
}
