/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_aux_aux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:17:56 by albealva          #+#    #+#             */
/*   Updated: 2024/11/16 10:38:58 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_trunc(const char *section, t_general *info, t_tokenargs *args)
{
	if (section[args->i] == '>' && section[args->i + 1] != '>'
		&& !args->in_single_quotes && !args->in_double_quotes)
	{
		if (args->current_token)
		{
			if (args->is_first_token)
				add_token_to_list(info, args->current_token, CMD);
			else
				add_token_to_list(info, args->current_token, ARG);
			args->current_token = NULL;
			args->j = reset_positions(args->start_pos, args->size_malloc);
			args->j = 0;
		}
		add_token_to_list(info, ">", TRUNC);
		args->current_token = NULL;
		args->expect_file = 1;
		args->j = reset_positions(args->start_pos, args->size_malloc);
		args->j = 0;
	}
}

void	ft_doble_input(const char *section, t_general *info, t_tokenargs *args)
{
	if (section[args->i] == '<' && section[args->i + 1] == '<'
		&& !args->in_single_quotes && !args->in_double_quotes)
	{
		if (args->current_token)
		{
			if (args->is_first_token)
				add_token_to_list(info, args->current_token, CMD);
			else
				add_token_to_list(info, args->current_token, ARG);
			args->current_token = NULL;
			args->j = reset_positions(args->start_pos, args->size_malloc);
			args->j = 0;
		}
		add_token_to_list(info, "<<", INPUT);
		args->current_token = NULL;
		args->i++;
		args->expect_file = 1;
		args->is_first_token = 0;
		args->j = reset_positions(args->start_pos, args->size_malloc);
		args->j = 0;
	}
}

void	ft_single_input(const char *section, t_general *info, t_tokenargs *args)
{
	if (section[args->i] == '<' && !args->in_single_quotes
		&& !args->in_double_quotes)
	{
		if (args->current_token)
		{
			if (args->is_first_token)
				add_token_to_list(info, args->current_token, CMD);
			else
				add_token_to_list(info, args->current_token, ARG);
			args->current_token = NULL;
			args->j = reset_positions(args->start_pos, args->size_malloc);
			args->j = 0;
		}
		add_token_to_list(info, "<", INPUT);
		args->current_token = NULL;
		args->expect_file = 1;
		args->j = reset_positions(args->start_pos, args->size_malloc);
		args->j = 0;
	}
}

void	ft_pipe(const char *section, t_general *info, t_tokenargs *args)
{
	if (section[args->i] == '|' && !args->in_single_quotes
		&& !args->in_double_quotes)
	{
		args->is_first_token = 1;
		if (args->current_token)
		{
			if (args->is_first_token)
				add_token_to_list(info, args->current_token, CMD);
			else
				add_token_to_list(info, args->current_token, ARG);
			args->current_token = NULL;
			args->j = reset_positions(args->start_pos, args->size_malloc);
			args->j = 0;
		}
		while (section[args->i] == '|')
		{
			add_token_to_list(info, "|", PIPE);
			args->current_token = NULL;
			args->i++;
			args->is_first_token = 1;
			args->j = reset_positions(args->start_pos, args->size_malloc);
			args->j = 0;
		}
	}
}

void	ft_space(const char *section, t_general *info, t_tokenargs *args)
{
	if (ft_isspace(section[args->i]) && !args->in_single_quotes
		&& !args->in_double_quotes)
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
			if (args->expect_file == 0)
				args->is_first_token = 0;
			args->expect_file = 0;
		}
	}
}
