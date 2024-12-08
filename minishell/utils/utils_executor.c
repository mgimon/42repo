/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:38:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/20 21:37:39 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_child_process(t_section *current, int prev_fd, int pipefd[2])
{
	if (current->next == NULL)
	{
		pipefd[0] = -1;
		pipefd[1] = -1;
	}
	child_process(current, prev_fd, pipefd);
}

void	create_pipe_if_needed(t_section *current, int pipefd[2])
{
	if (current->next != NULL)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
}

// printf("Process was killed by signal %d\n", WTERMSIG(status));
// info->exit_status = WTERMSIG(status);
// info->exit_status = WEXITSTATUS(status);
void	wait_for_sections(t_general *info)
{
	t_section	*tmp_sec;
	int			status;

	tmp_sec = info->sections;
	while (tmp_sec)
	{
		waitpid(tmp_sec->pid, &status, 0);
		tmp_sec = tmp_sec->next;
	}
	if (WIFEXITED(status))
	{
		printf("Process exited with status %d\n", WEXITSTATUS(status));
		info->exit_status = WEXITSTATUS(status);
	}
	else if (WIFSIGNALED(status))
	{
		info->exit_status = 131;
		if (WTERMSIG(status) == 2)
			info->exit_status = 130;
	}
	else if (WIFSTOPPED(status))
	{
		printf("Process was stopped by signal %d\n", WSTOPSIG(status));
		info->exit_status = WSTOPSIG(status);
	}
}
