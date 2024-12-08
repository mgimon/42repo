/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_14.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:35:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/10/27 22:12:31 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	upwds_one(t_section *current, char *tmp,
		char **var_pwd, char **var_oldpwd)
{
	char	*clean_home;

	clean_home = get_home(current->info->env);
	if ((count_lines(current->cmdv) == 1)
		|| (ft_strcmp(current->cmdv[1], "~") == 0))
		chdir(clean_home);
	update_oldpwd(var_oldpwd, var_pwd);
	tmp = ft_strjoin("PWD=", clean_home);
	free(*var_pwd);
	*var_pwd = ft_strdup(tmp);
	free(tmp);
	free(clean_home);
}

void	upwds_two(char **var_pwd, char **var_oldpwd)
{
	update_oldpwd(var_oldpwd, var_pwd);
	free(*var_pwd);
	*var_pwd = ft_strjoin("PWD=", "/");
}

void	upwds_three(t_section *current, char **var_pwd, char **var_oldpwd)
{
	update_oldpwd(var_oldpwd, var_pwd);
	change_last_subdir(current, var_pwd);
}

void	upwds_four(t_section *current, char *tmp,
		char **var_pwd, char **var_oldpwd)
{
	update_oldpwd(var_oldpwd, var_pwd);
	tmp = ft_strjoin("PWD=", current->cmdv[1]);
	free(*var_pwd);
	*var_pwd = ft_strdup(tmp);
	free(tmp);
}

void	upwds_five(t_section *current, char *tmp,
		char **var_pwd, char **var_oldpwd)
{
	update_oldpwd(var_oldpwd, var_pwd);
	free(*var_pwd);
	tmp = ft_strjoin(((*var_oldpwd) + 3), "/");
	*var_pwd = ft_strjoin(tmp, current->cmdv[1]);
	free(tmp);
}
