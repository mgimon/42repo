/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_aux_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:40:14 by albealva          #+#    #+#             */
/*   Updated: 2024/11/11 13:44:19 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

const char	*get_token_type_name(int type)
{
	static const char	*token_type_names[10];

	token_type_names[0] = "EMPTY";
	token_type_names[1] = "CMD";
	token_type_names[2] = "ARG";
	token_type_names[3] = "TRUNC";
	token_type_names[4] = "APPEND";
	token_type_names[5] = "INPUT";
	token_type_names[6] = "FIL";
	token_type_names[7] = "PIPE";
	token_type_names[8] = "END";
	if (type >= 0 && type <= 9)
		return (token_type_names[type]);
	else
		return ("UNKNOWN");
}

void	free_tokens_list_tokenize(t_general *info)
{
	t_token	*current;
	t_token	*next;

	current = info->tokens_list;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
	info->tokens_list = NULL;
	info->number_of_tokens = 0;
}

void	quoting_choice(t_quote_state *state, char c)
{
	if (c == '"' && state->sq == 0)
	{
		if (state->dq == 0)
			state->dq = 1;
		else
			state->dq = 0;
	}
	else if (c == '\'' && state->dq == 0)
	{
		if (state->sq == 0)
			state->sq = 1;
		else
			state->sq = 0;
	}
}

int	open_quote(char *line, t_quote_state *state)
{
	int	i;

	i = 0;
	state->dq = 0;
	state->sq = 0;
	while (line[i] != '\0')
	{
		quoting_choice(state, line[i]);
		i++;
	}
	if (state->dq != 0 || state->sq != 0)
	{
		printf("unclosed quotes error \n");
		return (1);
	}
	return (0);
}
