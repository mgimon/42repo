/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sintax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:00:35 by albealva          #+#    #+#             */
/*   Updated: 2024/12/02 20:33:47 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
int	check_first_command(t_token *current_token, t_general *info)
{
	if (current_token->type == CMD)
	{
		if (!is_valid_command(info, current_token->str, info->env))
		{
			printf("Error: Command '%s' not found.\n", current_token->str);
			g_global_status = 127;
			return (1);
		}
	}
	return (0);
}

int	check_command(t_general *info, t_token *current_token, int *last_type)
{
	if (current_token->type == CMD)
	{
		if (!is_valid_command(info, current_token->str, info->env))
		{
			printf("Error: Command '%s' not found.\n", current_token->str);
			g_global_status = 127;
			return (1);
		}
		*last_type = CMD;
	}
	return (0);
}
*/

int	check_argument(t_token *current_token, int *last_type)
{
	if (current_token->type == ARG)
	{
		if (*last_type == PIPE)
		{
			printf("Error: Argument '%s' in invalid position after pipe.\n",
				current_token->str);
			g_global_status = 2;
			return (1);
		}
		*last_type = ARG;
	}
	return (0);
}

void	print_redirection_error(t_token *current_token)
{
	if (current_token->type == TRUNC)
		printf("Error: No file specified for redirection '>'\n");
	else if (current_token->type == APPEND)
		printf("Error: No file specified for redirection '>>'\n");
	else if (current_token->type == INPUT)
		printf("Error: No file specified for redirection '<'\n");
}

int	check_redirection(t_token *current_token)
{
	if (current_token->type == TRUNC || current_token->type == APPEND
		|| current_token->type == INPUT)
	{
		if ((!current_token->prev) || (current_token->prev->type != CMD
				&& current_token->prev->type != ARG
				&& current_token->prev->type != PIPE))
		{
			if (current_token->type == TRUNC)
				printf("Error: Redirection op. '>' in invalid position.\n");
			else if (current_token->type == APPEND)
				printf("Error: Redirection op. '>>' in invalid position.\n");
			else
				printf("Error: Redirection op. '<' in invalid position.\n");
			g_global_status = 2;
			return (1);
		}
		if (current_token->next == NULL || current_token->next->type != FIL)
		{
			print_redirection_error(current_token);
			g_global_status = 2;
			return (1);
		}
		current_token = current_token->next;
	}
	return (0);
}
