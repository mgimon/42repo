/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_23.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:21:30 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/25 20:26:13 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	psnorminetter(const char **start, int *count, char ***path_parts,
		int *length)
{
	if (ft_strncmp(*start, "..", 2) == 0)
		*count = handle_double_dot(*path_parts, *count);
	else if (ft_strncmp(*start, ".", 1) != 0)
	{
		*count = copy_path_part(*start, *length, *path_parts, *count);
		if (*count == -1)
			return (-1);
	}
	return (0);
}

void	handle_forks(t_section **current, int *prev_fd, int (*pipefd)[2])
{
	if ((*current)->pid == 0)
	{
		if ((*current)->cmdv[0])
		{
			if ((ft_strcmp((*current)->cmdv[0], "grep") == 0
					|| ft_strcmp((*current)->cmdv[0], "cat") == 0)
				&& (*current)->nofile == 1)
				exit(0);
		}
		handle_child_process(*current, *prev_fd, *pipefd);
		setup_signals(0);
	}
	else
		parent_process(&(*current), &(*prev_fd), *pipefd);
}

void	exexport_printerr(t_section *current, int n)
{
	put_str_fd(2, "export: ");
	put_str_fd(2, current->cmdv[n]);
	put_str_fd(2, ": not a valid identifier\n");
	current->info->exit_status = 1;
}

void	excd_helper(t_section *current, char **var_pwd, char **var_oldpwd,
		char ***new_env)
{
	update_pwds(current, &(*var_pwd), &(*var_oldpwd));
	*new_env = new_wd_environment(current->info->env, *var_pwd, *var_oldpwd);
	matrix_free(current->info->env);
	free(*var_pwd);
	if (*var_oldpwd)
		free(*var_oldpwd);
	current->info->env = *new_env;
	if_clean_complex_route(current);
	if_backdirs_only(current);
}

void	excd_helper_two(t_section *current, char **var_pwd, char **var_oldpwd)
{
	put_str_fd(2, "cd: no such file or directory: ");
	put_str_fd(2, current->cmdv[1]);
	put_str_fd(2, "\n");
	if (*var_pwd)
		free(*var_pwd);
	if (*var_oldpwd)
		free(*var_oldpwd);
}
