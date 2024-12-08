/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:25:08 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/19 20:30:01 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_section_objects_helper(t_section *section, t_token *first, int s)
{
	allocate_heredocs(section, first, s);
	set_files_section(section, first, s);
	set_cmdv_section(section, first, s);
}

void	set_cmdv_section_helper(t_section *section, char **cmdv, int i)
{
	cmdv[i] = NULL;
	section->cmdv = cmdv;
}

void	open_truncate(t_section *section, t_file *tmp)
{
	if (section->fd_write != -1)
		close(section->fd_write);
	section->fd_write = open(tmp->string, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (section->fd_write == -1)
	{
		put_str_fd(2, tmp->string);
		put_str_fd(2, ": No such file or directory\n");
		section->nofile = 1;
		return ;
	}
}

void	open_append(t_section *section, t_file *tmp)
{
	if (section->fd_write != -1)
		close(section->fd_write);
	section->fd_write = open(tmp->string, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (section->fd_write == -1)
	{
		put_str_fd(2, tmp->string);
		put_str_fd(2, ": No such file or directory\n");
		section->nofile = 1;
		return ;
	}
}

void	close_prev_fdread(t_section *section)
{
	if (section->fd_read != -1)
		close(section->fd_read);
}
