/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_13.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:35:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/10/27 22:12:31 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_lastdir(t_section *current, char **var_pwd)
{
	int		i;
	int		n;
	char	*new_varpwd;

	i = 0;
	n = 0;
	if (!(*var_pwd) || !(current->cmdv)
		|| count_lines(current->cmdv) == 1)
		return ;
	if (ft_strcmp(current->cmdv[1], "..") != 0
		&& ft_strcmp(current->cmdv[1], "/..") != 0
		&& ft_strcmp(current->cmdv[1], "../") != 0)
		return ;
	if (ft_strcmp((*var_pwd), "PWD=") == 0)
		return ;
	while ((*var_pwd)[i])
		i++;
	while ((*var_pwd)[i] != '/' && (*var_pwd)[i] != '=')
		i--;
	new_varpwd = malloc(sizeof(char) * (i + 1));
	remove_lastdir_helper(new_varpwd, var_pwd, &i, &n);
	free(*var_pwd);
	*var_pwd = new_varpwd;
}

void	change_last_subdir_helper(char **var_pwd, char *result, int *i, int *n)
{
	*i = 0;
	while ((*i) < (*n))
	{
		result[*i] = (*var_pwd)[*i];
		(*i)++;
	}
	result[*i] = '\0';
}

void	change_last_subdir(t_section *current, char **var_pwd)
{
	int		i;
	int		n;
	char	*result;
	char	*tmp;

	if (!current->cmdv || !var_pwd)
		return ;
	i = 0;
	while ((*var_pwd)[i])
		i++;
	n = i;
	while ((*var_pwd)[n] != '/' && n > 0)
		n--;
	result = malloc(sizeof(char) * (n + 1));
	if (!result)
		return ;
	change_last_subdir_helper(var_pwd, result, &i, &n);
	tmp = ft_strjoin(result, (current->cmdv[1] + 2));
	free(result);
	free(*var_pwd);
	*var_pwd = ft_strdup(tmp);
	free(tmp);
}

int	has_dots_and_subdir(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	while (i > 0)
	{
		if (i >= 2 && str[i] == '/')
		{
			if (str[i - 1] == '.')
			{
				if (str[i - 2] == '.')
					return (1);
			}
		}
		i--;
	}
	return (0);
}

void	update_oldpwd(char **var_oldpwd, char **var_pwd)
{
	if (*var_oldpwd)
	{
		free(*var_oldpwd);
		*var_oldpwd = ft_strjoin("OLD", *var_pwd);
	}
}
