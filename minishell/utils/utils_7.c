/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:26:39 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/14 20:54:31 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_if_no_cmdv(t_section *section, int *i)
{
	*i = 0;
	if (!section->cmdv || !section->cmdv[0])
		exit(0);
}

void	set_cmd_in_paths_helper(t_section *section, char *new_path, int i)
{
	free(section->paths[i]);
	section->paths[i] = new_path;
	new_path = NULL;
}

int	count_lines(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	allocate_heredocs_helper(t_token *tmp,
t_heredoc *tmp_hdocs, t_heredoc *new_hdoc, int count)
{
	while (tmp)
	{
		if (ft_strcmp(tmp->str, "<<") == 0)
		{
			if (!tmp->next)
				break ;
			tmp_hdocs->delimiter = ft_strdup((tmp->next)->str);
			pipe(tmp_hdocs->fds);
			count--;
			if (count > 0)
			{
				new_hdoc = malloc(sizeof(t_heredoc));
				tmp_hdocs->next = new_hdoc;
				tmp_hdocs = new_hdoc;
			}
			else
			{
				tmp_hdocs->next = NULL;
				break ;
			}
		}
		tmp = tmp->next;
	}
}

void	clean_str_exit_helper(char *result, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '\0';
}
