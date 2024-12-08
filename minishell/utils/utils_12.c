/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_12.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:35:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/20 20:18:08 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_endslash(char **var)
{
	int		i;
	int		n;
	char	*newvar;

	i = 0;
	n = 0;
	while ((*var)[i])
		i++;
	i--;
	if ((*var)[i] != '/')
		return ;
	newvar = malloc(sizeof(char) * (i + 1));
	while (n < i)
	{
		newvar[n] = (*var)[n];
		n++;
	}
	newvar[n] = '\0';
	free(*var);
	*var = newvar;
}

int	remove_dots_helper(char *var_pwd, int *i, char c)
{
	(*i)--;
	if (var_pwd[*i] != c)
		return (0);
	return (1);
}

int	remove_dots(char **var_pwd)
{
	int		i;
	int		n;
	char	*new_varpwd;

	i = 0;
	n = 0;
	while ((*var_pwd)[i])
		i++;
	if (i < 7)
		return (0);
	if (!remove_dots_helper((*var_pwd), &i, '.'))
		return (0);
	if (!remove_dots_helper((*var_pwd), &i, '.'))
		return (0);
	if (!remove_dots_helper((*var_pwd), &i, '/'))
		return (0);
	new_varpwd = malloc(sizeof(char) * (i + 1));
	while (n < i)
	{
		new_varpwd[n] = (*var_pwd)[n];
		n++;
	}
	new_varpwd[n] = '\0';
	free(*var_pwd);
	return (*var_pwd = new_varpwd, 1);
}

void	remove_lastdir_helper(char *new_varpwd, char **var_pwd, int *i, int *n)
{
	while ((*n) < (*i))
	{
		new_varpwd[*n] = (*var_pwd)[*n];
		(*n)++;
	}
	if ((*var_pwd)[*i] == '=')
	{
		new_varpwd[*n] = (*var_pwd)[*n];
		(*n)++;
	}
	new_varpwd[*n] = '\0';
}

void	remove_var_from_exports(t_section *current, char *var_equal)
{
	int		i;
	int		n;
	int		total_exports;
	char	*linedeclare;
	char	**new_exports;

	i = 0;
	n = -1;
	if (!current || !current->cmdv || !current->info->exports
		|| !current->cmdv[1])
		return ;
	while (current->info->exports[i])
	{
		linedeclare = ft_strjoin("declare -x ", var_equal);
		if (ft_strncmp_pipex(linedeclare, current->info->exports[i],
				ft_strlen(linedeclare)) == 0)
			n = i;
		free(linedeclare);
		i++;
	}
	if (n == -1)
		return ;
	removevar_norminetter(current, &total_exports, &new_exports, n);
}
