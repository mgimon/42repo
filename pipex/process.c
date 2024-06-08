/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:18:23 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/08 17:31:18 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//execve frees and kills the process if successful
void	child_process(t_struct *structure, char **argv, char **env, int *sides)
{
	struct_init(structure, argv, env, 1);
	close(sides[0]);
	dup2(structure->fd, STDIN_FILENO);
	dup2(sides[1], STDOUT_FILENO);
	close(structure->fd);
	close(sides[1]);
	if (execve(structure->path_cmd, structure->cmd, NULL) == -1)
	{
		matrix_free(structure->path);
		matrix_free(structure->cmd);
		free(structure->path_cmd);
		perror("");
		exit(1);
	}
}


//execve frees and kills the process if successful
void	parent_process(t_struct *structure, char **argv, char **env, int *sides)
{
	struct_init(structure, argv, env, 2);
	close(sides[1]);
	dup2(sides[0], STDIN_FILENO);
	close(sides[0]);
	dup2(structure->fd, STDOUT_FILENO);
	close(structure->fd);
	if (execve(structure->path_cmd, structure->cmd, NULL) == -1)
	{
		matrix_free(structure->path);
		matrix_free(structure->cmd);
		free(structure->path_cmd);
		perror("");
		exit(1);
	}
}

void	pipex(t_struct *structure, char **argv, char **env)
{
	pid_t	process;
	int	sides[2];
	
	if (pipe(sides) == -1)
	{
		perror("");
		exit(1);
	}
	process = fork();
	if (process < 0)
	{
		perror("");
		close(sides[0]);
		close(sides[1]);
		exit(1);
	}
	if (process == 0)
		child_process(structure, argv, env, sides);
	else
	{
		/*wait(NULL);*/
		parent_process(structure, argv, env, sides);
	}
}
