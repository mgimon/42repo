/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:58:22 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/20 19:27:31 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_files_per_section(t_token *first)
{
	int		result;
	t_token	*tmp;

	result = 0;
	tmp = first;
	while (tmp && tmp->type != 7)
	{
		if (tmp->type == 6)
			result++;
		tmp = tmp->next;
	}
	return (result);
}

int	count_cmdvs_per_section(t_token *first)
{
	int		result;
	t_token	*tmp;

	result = 0;
	tmp = first;
	while (tmp && tmp->type != 7)
	{
		if (tmp->type == 1)
		{
			result++;
			tmp = tmp->next;
			while (tmp && tmp->type == 2)
			{
				result++;
				tmp = tmp->next;
			}
		}
		else
			tmp = tmp->next;
	}
	return (result);
}

t_token	*get_first_in_section(t_token *first, int s)
{
	t_token	*tmp;
	int		j;

	tmp = first;
	j = 0;
	while (tmp && j < s)
	{
		if (tmp->type == 7)
			j++;
		tmp = tmp->next;
	}
	return (tmp);
}

void	add_file_to_files(t_token *section_first, t_file *files, int *i, int n)
{
	if (!section_first)
		return ;
	files[*i].string = ft_strdup((section_first->next)->str);
	if (ft_strcmp(section_first->str, "<<") == 0)
		files[*i].open_mode = 9;
	else
		files[*i].open_mode = section_first->type;
	if (*i == (n - 1))
		files[*i].next = NULL;
	else
		files[*i].next = &files[*i + 1];
	(*i)++;
}

void	open_files_section(t_section *section)
{
	t_file		*tmp;
	t_heredoc	*tmp_hdocs;

	tmp = section->files;
	tmp_hdocs = section->heredocs;
	while (tmp)
	{
		if (tmp->open_mode == 3)
			open_truncate(section, tmp);
		else if (tmp->open_mode == 4)
			open_append(section, tmp);
		else if (tmp->open_mode == 5 || tmp->open_mode == 9)
		{
			if (open_files_section_helper(section, &tmp, &tmp_hdocs) == 1)
				return ;
		}
		tmp = tmp->next;
	}
}
