/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_22.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:19:39 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/20 20:18:04 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_files_section_helper(t_section *section, t_file **tmp,
		t_heredoc **tmp_hdocs)
{
	close_prev_fdread(section);
	if ((*tmp)->open_mode == 9)
	{
		if (*tmp_hdocs)
			section->fd_read = (*tmp_hdocs)->fds[0];
		*tmp_hdocs = (*tmp_hdocs)->next;
	}
	else
	{
		section->fd_read = open((*tmp)->string, O_RDONLY);
		if (section->fd_read == -1)
		{
			put_str_fd(2, (*tmp)->string);
			put_str_fd(2, ": No such file or directory\n");
			section->nofile = 1;
			return (1);
		}
	}
	return (0);
}

int	heredocs_norminetter_one(t_section *section, t_token **tmp, int s,
		int *section_index)
{
	while (*tmp && *section_index < s)
	{
		if ((*tmp)->type == 7)
			(*section_index)++;
		*tmp = (*tmp)->next;
	}
	if (!(*tmp))
	{
		section->heredocs = NULL;
		return (1);
	}
	return (0);
}

void	heredocs_norminetter_two(t_section *section, t_token **tmp,
		t_token **section_start, int count)
{
	t_heredoc	*tmp_hdocs;
	t_heredoc	*new_hdoc;

	new_hdoc = NULL;
	section->heredocs = malloc(sizeof(t_heredoc));
	tmp_hdocs = section->heredocs;
	*tmp = *section_start;
	allocate_heredocs_helper(*tmp, tmp_hdocs, new_hdoc, count);
}

int	write_heredocs_norminetter(int *len, char **expanded, t_heredoc **tmp_hdoc)
{
	*len = ft_strlen(*expanded) + 1;
	if (write((*tmp_hdoc)->fds[1], *expanded, (*len) - 1) == -1)
	{
		free(*expanded);
		return (1);
	}
	write((*tmp_hdoc)->fds[1], "\n", 1);
	free(*expanded);
	return (0);
}

void	removevar_norminetter(t_section *current, int *total_exports,
		char ***new_exports, int n)
{
	*total_exports = count_exports(current->info->exports);
	*new_exports = copy_exports(current->info->exports, n, *total_exports);
	matrix_free(current->info->exports);
	current->info->exports = *new_exports;
}
