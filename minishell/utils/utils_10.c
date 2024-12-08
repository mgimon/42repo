/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:19:11 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/10/28 20:38:54 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	search_var_env(char ***env, char *var_name, size_t env_len)
{
	size_t	i;

	i = 0;
	while (i < env_len)
	{
		if (compare_var_name((*env)[i], var_name))
			return (1);
		i++;
	}
	free(var_name);
	return (0);
}

int	check_all_env(char ***env, char *var, char **var_name, size_t *env_len)
{
	if (!env || !*env || !var)
		return (0);
	*var_name = get_var_name(var);
	if (!*var_name)
		return (0);
	*env_len = 0;
	while ((*env)[(*env_len)])
		(*env_len)++;
	if (!search_var_env(env, *var_name, *env_len))
		return (0);
	return (1);
}

void	set_new_env(char **new_env, size_t j, char *var_name, char ***env)
{
	if (!new_env[j - 1])
	{
		free(var_name);
		free(new_env);
		return ;
	}
	new_env[j] = NULL;
	free(var_name);
	free(*env);
	*env = new_env;
}

int	check_new_env(char **newenv, int i)
{
	if (newenv[i] == NULL)
	{
		while (--i >= 0)
			free(newenv[i]);
		free(newenv);
		return (0);
	}
	return (1);
}

//free(var_equal);
void	set_new_env_2(t_section *current, char **new_env, char *var_equal)
{
	(void)var_equal;
	var_equal = NULL;
	matrix_free(current->info->env);
	current->info->env = new_env;
	if (ft_strcmp(current->cmdv[1], "PATH") == 0)
	{
		matrix_free(current->info->paths);
		current->info->paths = NULL;
	}
}
