/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:42:20 by albealva          #+#    #+#             */
/*   Updated: 2024/12/02 20:42:14 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_pipe(t_token *ct, int *last_type)
{
	if (ct->type == PIPE && ct->next == NULL)
	{
		put_str_fd(2, "Error1: Pipe operator at the end of command.\n");
		g_global_status = 2;
		return (1);
	}
	if (ct->type == PIPE)
	{
		if (ct->prev->type == PIPE || ct->prev->type == TRUNC
			|| ct->prev->type == APPEND || ct->prev->type == INPUT)
		{
			put_str_fd(2, "Error2: Pipe operator in invalid position.\n");
			g_global_status = 2;
			return (1);
		}
		*last_type = PIPE;
	}
	return (0);
}

int	check_last_token(int last_type)
{
	char	*operator;

	operator = NULL;
	if (last_type == PIPE || last_type == TRUNC || last_type == APPEND
		|| last_type == INPUT)
	{
		if (last_type == PIPE)
			operator = "|";
		else if (last_type == TRUNC)
			operator = ">";
		else if (last_type == APPEND)
			operator = ">>";
		else if (last_type == INPUT)
			operator = "<";
		printf("Error: Expected an argument or cmd after '%s'.\n", operator);
		g_global_status = 2;
		return (1);
	}
	return (0);
}

int	check_pipe_at_start(t_token *current_token)
{
	if (current_token->type == PIPE)
	{
		put_str_fd(2, "Error: Pipe operator in invalid position.\n");
		g_global_status = 2;
		return (1);
	}
	return (0);
}

int	check_first(t_token *current_token, t_general *info)
{
	(void)info;
	if (!current_token)
	{
		g_global_status = 2;
		return (1);
	}
	if (check_pipe_at_start(current_token))
	{
		g_global_status = 2;
		return (1);
	}
	if ((current_token->type == TRUNC || current_token->type == APPEND
			|| current_token->type == INPUT) && !current_token->next)
	{
		g_global_status = 2;
		return (printf("Error: syntax error near unexpected token\n"), 1);
	}
	return (0);
}

int	check_syntax_errors(t_general *info)
{
	t_token	*current_token;
	int		last_type;

	current_token = info->tokens_list;
	last_type = 0;
	if (!current_token)
		return (1);
	if (check_pipe_at_start(current_token))
		return (1);
	if (check_first(current_token, info))
		return (1);
	current_token = current_token->next;
	while (current_token != NULL)
	{
		if (check_argument(current_token, &last_type))
			return (1);
		if (check_redirection(current_token))
			return (1);
		if (check_pipe(current_token, &last_type))
			return (1);
		current_token = current_token->next;
	}
	return (0);
}

/*
int	error_pipe(void)
{
	fprintf(stderr, "Error: Pipe error\n");
	g_global_status = 2;
	return (1);
}

int	error_cmd(t_token *current_token)
{
	fprintf(stderr, "Error: Command '%s' not found.\n", current_token->str);
	g_global_status = 127;
	return (1);
}

int	error_pipe2	(t_token *current_token)
{
	fprintf(stderr, "Error: Argument '%s' in invalid position after pipe.\n",
		current_token->str);
	g_global_status = 2;
	return (1);
}

int	error_redirect(t_token *current_token)
{
	fprintf(stderr, "Error: Redirection operator '%s' in invalid position.\n",
				current_token->type == TRUNC ? ">" : current_token->type ==
				APPEND ? ">>" : "<");
	g_global_status = 2;
	return (1);
}

int	error_file(t_token *current_token)
{
	fprintf(stderr, "Error: No file specified for redirection '%s'.\n",
					current_token->type == TRUNC ? ">" : current_token->type ==
					APPEND ? ">>" : "<");
	g_global_status = 2;
	return (1);
}

int	error_pipe3(t_token *current_token)
{
	(void)current_token;
	fprintf(stderr, "Error: Pipe operator in invalid position.\n");
				g_global_status = 2;
	return (1);
}

int	error_last(int last_type)
{
	printf("Error: Incomplete command,
		expected an argument or command after '%s'.\n",
		last_type == PIPE ? "|" : last_type == TRUNC ? ">" : last_type ==
		APPEND ? ">>" : "<");
	g_global_status = 2;
	return (1);
}

void	update_to_file_and_advance(t_token **current_token, int *last_type) {
	*last_type = FIL;              // Actualiza el último tipo procesado
	*current_token = (*current_token)->next; // Avanza al siguiente token
}

int	check_syntax_errors(t_general *info)
{
	t_token	*current_token;
	int		last_type;

	last_type = 0;
	current_token = info->tokens_list;
	if (!current_token)
		return (1);
	if (current_token && current_token->type == PIPE)
		return (error_pipe());
	if (current_token && current_token->type == CMD)
	{
		if (!is_valid_command(info, current_token->str, info->env))
			return (error_cmd(current_token));
		last_type = CMD;
	}
	current_token = current_token->next;
	while (current_token != NULL)
	{
		if (current_token->type == CMD)
		{
			if (!is_valid_command(info, current_token->str, info->env))
				return(error_cmd(current_token));
			last_type = CMD;
		}
		else if (current_token->type == ARG)
		{
			if (last_type == PIPE)
				return (error_pipe2(current_token));
			last_type = ARG;
		} else if (current_token->type == TRUNC || current_token->type == APPEND
			|| current_token->type == INPUT) {
			if (last_type != ARG && last_type !=CMD && last_type!=PIPE)
					return (error_redirect(current_token));
			if (current_token->next == NULL || current_token->next->type != FIL)
					return (error_file(current_token));
			last_type = FIL;
			current_token = current_token->next;
		}
		else if (current_token->type == PIPE)
		{
			if (last_type == PIPE || last_type == TRUNC || last_type == APPEND
				|| last_type == INPUT)
				return (error_pipe3(current_token));
			last_type = PIPE;
		}
		current_token = current_token->next;
	}
	if (last_type == PIPE || last_type == TRUNC || last_type == APPEND
		|| last_type == INPUT) {
			return (error_last(last_type));
	}
	return (0);
}

*/
