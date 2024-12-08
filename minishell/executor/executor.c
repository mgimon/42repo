/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:26:37 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/02 21:06:49 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_input_redirection(t_section *current, int prev_fd)
{
	if (current->fd_read != -1)
	{
		dup2(current->fd_read, STDIN_FILENO);
		close(current->fd_read);
	}
	else if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
}

void	handle_output_redirection(t_section *current, int *pipefd)
{
	if (current->fd_write != -1)
	{
		dup2(current->fd_write, STDOUT_FILENO);
		close(current->fd_write);
	}
	else if (current->next != NULL)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
	}
	else if (current->next == NULL && current->fd_write == -1)
		close(pipefd[0]);
}

void	child_process(t_section *current, int prev_fd, int *pipefd)
{
	write_in_heredocs(current, current->info);
	setup_signals(1);
	if (!current->cmdv[0])
		exit(0);
	handle_input_redirection(current, prev_fd);
	handle_output_redirection(current, pipefd);
	if (exec_if_builtin_1(current) == 0)
	{
		free_files(current->files);
		free_sections_list(current->info->sections);
		exit(0);
	}
	execve(current->path, current->cmdv, current->info->env);
	put_str_fd(2, current->cmdv[0]);
	put_str_fd(2, ": Command not found\n");
	g_global_status = 127;
	current->info->exit_status = 127;
	exit(127);
}

// close_all_process_files();
void	parent_process(t_section **current, int *prev_fd, int *pipefd)
{
	close_section_hdocs_parent(*current);
	if (*prev_fd != -1)
		close(*prev_fd);
	if ((*current)->fd_read != -1)
		close((*current)->fd_read);
	if ((*current)->fd_write != -1 && (*current)->next == NULL)
		close((*current)->fd_write);
	if ((*current)->next != NULL)
	{
		close(pipefd[1]);
		*prev_fd = pipefd[0];
	}
	if ((*current)->cmdv[0])
		exec_if_builtin_2(*current);
	*current = (*current)->next;
}

void	executor(t_general *info)
{
	t_section	*current;
	int			pipefd[2];
	int			prev_fd;

	prev_fd = -1;
	current = info->sections;
	setup_signals(1);
	while (current != NULL)
	{
		create_pipe_if_needed(current, pipefd);
		setup_signals(3);
		current->pid = fork();
		if (current->pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		handle_forks(&current, &prev_fd, &pipefd);
	}
	wait_for_sections(info);
	setup_signals(1);
	g_global_status = info->exit_status;
}
