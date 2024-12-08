/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:53:59 by albealva          #+#    #+#             */
/*   Updated: 2024/11/16 10:26:37 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_last_token(t_general *info, t_tokenargs *args)
{
	if (args->current_token)
	{
		if (args->expect_file)
			add_token_to_list(info, args->current_token, FIL);
		else if (args->is_first_token)
			add_token_to_list(info, args->current_token, CMD);
		else
			add_token_to_list(info, args->current_token, ARG);
		args->current_token = NULL;
		args->j = reset_positions(args->start_pos, args->size_malloc);
		args->j = 0;
		args->is_first_token = 0;
	}
}

void	ft_add_char(const char *section, t_general *info, t_tokenargs *args)
{
	args->current_token = add_char_to_token(info, args->current_token,
			section[args->i]);
	if (section[args->i] == '$' && !args->in_single_quotes
		&& args->current_token)
	{
		args->start_pos[args->j] = ft_strlen(args->current_token);
		args->j++;
	}
}

t_operator	identify_operator(const char *section, size_t i, t_tokenargs *args)
{
	if (section[i] == '\"')
		return (OP_DOUBLE_QUOTE);
	if (section[i] == '\'')
		return (OP_SINGLE_QUOTE);
	if (section[i] == '|' && !args->in_single_quotes && !args->in_double_quotes)
		return (OP_PIPE);
	if (section[i] == '>' && section[i + 1] == '>' && !args->in_single_quotes
		&& !args->in_double_quotes)
		return (OP_APPEND);
	if (section[i] == '>' && section[i + 1] != '>' && !args->in_single_quotes
		&& !args->in_double_quotes)
		return (OP_TRUNC);
	if (section[i] == '<' && section[i + 1] == '<' && !args->in_single_quotes
		&& !args->in_double_quotes)
		return (OP_DOUBLE_INPUT);
	if (section[i] == '<' && !args->in_single_quotes && !args->in_double_quotes)
		return (OP_SINGLE_INPUT);
	if (ft_isspace(section[i]) && !args->in_single_quotes
		&& !args->in_double_quotes)
		return (OP_SPACE);
	return (OP_NONE);
}

void	ft_operators(t_operator op, const char *section, t_general *info,
		t_tokenargs *args)
{
	if (op == OP_DOUBLE_QUOTE)
		ft_double_quote(section, info, args);
	else if (op == OP_SINGLE_QUOTE)
		ft_single_quote(section, info, args);
	else if (op == OP_PIPE)
		ft_pipe(section, info, args);
	else if (op == OP_APPEND)
		ft_append(section, info, args);
	else if (op == OP_TRUNC)
		ft_trunc(section, info, args);
	else if (op == OP_DOUBLE_INPUT)
		ft_doble_input(section, info, args);
	else if (op == OP_SINGLE_INPUT)
		ft_single_input(section, info, args);
	else if (op == OP_SPACE)
		ft_space(section, info, args);
}

void	extract_tokens(const char *section, t_general *info)
{
	t_tokenargs	args;
	t_operator	op;

	ft_init_token_args(&args, section);
	ft_init_expand(section, &args, info);
	while (section[args.i] != '\0')
	{
		op = identify_operator(section, args.i, &args);
		if (op != OP_NONE)
		{
			ft_operators(op, section, info, &args);
			if (op == OP_DOUBLE_QUOTE || op == OP_SINGLE_QUOTE || op == OP_PIPE)
			{
				continue ;
			}
		}
		else
		{
			ft_add_char(section, info, &args);
		}
		args.i++;
	}
	if (args.current_token)
		ft_last_token(info, &args);
}
