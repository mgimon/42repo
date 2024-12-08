/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_15.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:35:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/10/31 21:43:35 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_pwds(t_section *current, char **var_pwd, char **var_oldpwd)
{
	char	*tmp;

	tmp = NULL;
	if ((count_lines(current->cmdv) == 1)
		|| (ft_strcmp(current->cmdv[1], "~") == 0))
		upwds_one(current, tmp, var_pwd, var_oldpwd);
	else if (ft_strcmp(current->cmdv[1], ".") == 0)
		return ;
	else if (ft_strcmp(current->cmdv[1], "/") == 0)
		upwds_two(var_pwd, var_oldpwd);
	else if (has_dots_and_subdir(current->cmdv[1]))
		upwds_three(current, var_pwd, var_oldpwd);
	else if (has_slash(current->cmdv[1]))
		upwds_four(current, tmp, var_pwd, var_oldpwd);
	else
		upwds_five(current, tmp, var_pwd, var_oldpwd);
	remove_endslash(var_pwd);
	remove_endslash(var_oldpwd);
	remove_dots(var_pwd);
	remove_lastdir(current, var_pwd);
}

char	*get_var_pwd(t_section *current)
{
	int	i;

	i = 0;
	while (current->info->env[i])
	{
		if (ft_strncmp(current->info->env[i], "PWD=", 4) == 0)
			return (ft_strdup(current->info->env[i]));
		i++;
	}
	return (ft_strdup("PWD="));
}

char	*get_var_oldpwd(t_section *current)
{
	int	i;

	i = 0;
	while (current->info->env[i])
	{
		if (ft_strncmp(current->info->env[i], "OLDPWD=", 7) == 0)
			return (ft_strdup(current->info->env[i]));
		i++;
	}
	return (ft_strdup("OLDPWD="));
}

int	count_exports(char **exports)
{
	int	count;

	count = 0;
	while (exports[count])
		count++;
	return (count);
}

char	**copy_exports(char **exports, int omit_index, int total)
{
	char	**new_exports;
	int		j;
	int		k;

	k = 0;
	j = 0;
	new_exports = malloc(sizeof(char *) * (total));
	if (!new_exports)
		return (NULL);
	while (j < total)
	{
		if (j != omit_index)
		{
			new_exports[k] = ft_strdup(exports[j]);
			k++;
		}
		j++;
	}
	new_exports[k] = NULL;
	return (new_exports);
}
