/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:35:56 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/02 21:05:29 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_str_to_matrix(char ***matrix, char *str)
{
	int		i;
	char	*duplicate;
	char	**new_matrix;

	if (!matrix || !str)
		return ;
	i = 0;
	while ((*matrix) && (*matrix)[i])
		i++;
	new_matrix = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_matrix)
		return ;
	i = 0;
	while ((*matrix) && (*matrix)[i])
	{
		new_matrix[i] = ft_strdup((*matrix)[i]);
		i++;
	}
	duplicate = ft_strdup(str);
	new_matrix[i] = duplicate;
	new_matrix[i + 1] = NULL;
	if (*matrix)
		matrix_free(*matrix);
	*matrix = new_matrix;
}

void	allocate_heredocs(t_section *section, t_token *first, int s)
{
	t_token	*tmp;
	t_token	*section_start;
	int		count;
	int		section_index;

	tmp = first;
	count = 0;
	section_index = 0;
	if (!first)
		return ;
	if (heredocs_norminetter_one(section, &tmp, s, &section_index) == 1)
		return ;
	section_start = tmp;
	while (tmp && tmp->type != 7)
	{
		if (ft_strcmp(tmp->str, "<<") == 0)
			count++;
		tmp = tmp->next;
	}
	if (count == 0)
	{
		section->heredocs = NULL;
		return ;
	}
	heredocs_norminetter_two(section, &tmp, &section_start, count);
}

char	*clean_str_exit(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (NULL);
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		j++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (NULL);
	result = malloc(sizeof(char) * (j + 1));
	clean_str_exit_helper(result, str);
	return (result);
}

void	write_in_heredocs(t_section *current, t_general *info)
{
	char		buffer[1024];
	t_heredoc	*tmp_hdoc;

	setup_signals(2);
	tmp_hdoc = current->heredocs;
	if (!current || !current->heredocs)
		return ;
	while (tmp_hdoc)
	{
		write_in_heredocs_helper(tmp_hdoc, buffer, info);
		close(tmp_hdoc->fds[1]);
		if (buffer[0] == '\0')
			break ;
		tmp_hdoc = tmp_hdoc->next;
	}
	setup_signals(1);
}

void	close_section_hdocs_parent(t_section *current)
{
	t_heredoc	*tmp;

	tmp = current->heredocs;
	while (tmp)
	{
		close(tmp->fds[0]);
		close(tmp->fds[1]);
		tmp = tmp->next;
	}
}
