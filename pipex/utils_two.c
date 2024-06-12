/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:32:52 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/12 20:52:17 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_free_close(t_struct *structure)
{
	matrix_free(structure->cmd);
	close(structure->fd);
	perror("");
	exit(1);
}

int	there_is_path(t_struct *structure)
{
	int	i;

	i = 0;
	while (structure->path[i] != NULL)
	{
		if (access(structure->path[i], R_OK) == 0)
		{
			structure->path_cmd = ft_strdup(structure->path[i]);
			if (structure->path_cmd == NULL)
			{
				matrix_free(structure->path);
				error_free_close(structure);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	no_path_or_absolute_cmd(t_struct *structure, int which_cmd)
{
	if (which_cmd == 1)
	{
		if (access(structure->argv2, R_OK) == 0)
		{
			structure->path_cmd = ft_strdup(structure->argv2);
			if (structure->path_cmd == NULL)
				error_free_close(structure);
			return (1);
		}
	}
	else if (which_cmd == 2)
	{
		if (access(structure->argv3, R_OK) == 0)
		{
			structure->path_cmd = ft_strdup(structure->argv3);
			if (structure->path_cmd == NULL)
				error_free_close(structure);
			return (1);
		}
	}
	return (0);
}

void	set_values(t_struct *structure, char **argv, char **env, int which_cmd)
{
	char	**cmd;
	int		route_in_cmd;

	route_in_cmd = 0;
	structure->argv2 = argv[2];
	structure->argv3 = argv[3];
	if (which_cmd == 1)
	{
		cmd = ft_split(argv[2], ' ');
		cmd[0] = ft_strjoin("/", cmd[0]);
		if (ft_strchr(argv[2], '/'))
			route_in_cmd = 1;
	}
	else if (which_cmd == 2)
	{
		cmd = ft_split(argv[3], ' ');
		cmd[0] = ft_strjoin("/", cmd[0]);
		if (ft_strchr(argv[3], '/'))
			route_in_cmd = 1;
	}
	structure->cmd = cmd;
	set_cmd_in_path(structure, env, structure->cmd[0]);
	if (route_in_cmd > 0)
		structure->path = NULL;
	set_correct_path(structure, which_cmd);
}
