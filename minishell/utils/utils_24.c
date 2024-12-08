/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_24.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:07:18 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/25 21:58:47 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	rembackdirs_hlpr(t_section *current, int dirs_back, int *i,
		char ***split_pwd)
{
	if (dirs_back < 1)
		return (0);
	while (current->info->env[*i] != NULL)
	{
		if (ft_strncmp_pipex(current->info->env[*i], "PWD=", 4) == 0)
			break ;
		(*i)++;
	}
	if (!rembackdirs_hlpr_zero(current, *i, &(*split_pwd)))
		return (0);
	return (1);
}

int	rembackdirs_hlpr_zero(t_section *current, int i, char ***split_pwd)
{
	char	*pwd_line;

	if (current->info->env[i] == NULL)
		return (0);
	pwd_line = current->info->env[i] + 4;
	if (ft_strlen(pwd_line) == 0)
		return (0);
	*split_pwd = ft_split(pwd_line, '/');
	return (1);
}

void	rembackdirs_hlpr_one(char **new_pwd, char ***split_pwd, int new_len)
{
	size_t	needed_size;
	int		j;

	j = 0;
	while (j < new_len)
	{
		needed_size = ft_strlen(*new_pwd) + ft_strlen((*split_pwd)[j]) + 2;
		*new_pwd = realloc(*new_pwd, needed_size);
		ft_strcat(*new_pwd, (*split_pwd)[j]);
		if (j < new_len - 1)
			ft_strcat(*new_pwd, "/");
		j++;
	}
}

void	rembackdirs_hlpr_two(t_section *current, int i, char ***new_env,
		char **new_pwd)
{
	int	env_size;
	int	k;

	env_size = 0;
	while (current->info->env[env_size] != NULL)
		env_size++;
	*new_env = malloc((env_size + 1) * sizeof(char *));
	k = 0;
	while (k < env_size)
	{
		if (k == i)
			(*new_env)[k] = *new_pwd;
		else
			(*new_env)[k] = ft_strdup(current->info->env[k]);
		k++;
	}
	(*new_env)[k] = NULL;
}

void	idontevenknow_bro(t_general *info, t_section **section)
{
	(*section)->env = info->env;
	(*section)->info = info;
}
