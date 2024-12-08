/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_26.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:07:31 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/02 19:54:19 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_special_commands(const char *input, int *print_mode)
{
	if (strcmp(input, "print_on") == 0)
	{
		*print_mode = 1;
		printf("Print mode enabled\n");
	}
	else if (strcmp(input, "print_off") == 0)
	{
		*print_mode = 0;
		printf("Print mode disabled\n");
	}
}

void	handle_print_tokens(int **print_mode, t_general *info,
		t_token **current, t_token **token_list)
{
	if (**print_mode)
	{
		*current = *token_list;
		while (*current)
		{
			printf("Token: %s, Type: %s\n", (*current)->str,
				get_token_type_name((*current)->type));
			*current = (*current)->next;
		}
		printf("Total tokens: %d\n", info->number_of_tokens);
	}
}

void	ideka(t_general *info, char **input, t_token **token_list)
{
	*token_list = tokenize_input(info, *input);
	tokenize_input(info, *input);
}

// Maneja comandos especiales como 'print_on' y 'print_off'
void	handle_input(t_general *info, char *input, int *print_mode)
{
	char	*new_input;
	t_token	*token_list;
	t_token	*current;

	add_history(input);
	handle_special_commands(input, print_mode);
	if (!input)
		input = "\n";
	while (1)
	{
		new_input = extract_current_section(input, info);
		if (!new_input)
			break ;
		if (strcmp(input, new_input) == 0)
			break ;
		input = new_input;
	}
	ideka(info, &input, &token_list);
	if (token_list == NULL)
	{
		input = NULL;
		return ;
	}
	handle_print_tokens(&print_mode, info, &current, &token_list);
	return ;
}

void	routine(t_general *info, char **input)
{
	info->sections = create_sections_list(info);
	executor(info);
	free_heredocs(info);
	free_all_allocated_blocks(info);
	free_sections_list(info->sections);
	free(*input);
	*input = NULL;
}
