/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:43:24 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/14 20:28:24 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_heredocs(t_general *info)
{
	t_section	*section;
	t_heredoc	*current_heredoc;
	t_heredoc	*next_heredoc;

	section = info->sections;
	while (section)
	{
		current_heredoc = section->heredocs;
		while (current_heredoc)
		{
			next_heredoc = current_heredoc->next;
			if (current_heredoc->delimiter)
				free(current_heredoc->delimiter);
			free(current_heredoc);
			current_heredoc = next_heredoc;
		}
		section = section->next;
	}
}
