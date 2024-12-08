/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:16:45 by albealva          #+#    #+#             */
/*   Updated: 2024/11/16 10:32:54 by contubernio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_init_token_args(t_tokenargs *args, const char *section)
{
	args->i = 0;
	args->start_pos = NULL;
	args->size_malloc = count_dollars(section);
	args->j = 0;
	args->current_token = NULL;
	args->is_first_token = 1;
	args->expect_file = 0;
	args->in_single_quotes = 0;
	args->in_double_quotes = 0;
	args->k = 0;
}

void	ft_init_expand(const char *section, t_tokenargs *args, t_general *info)
{
	if (section && count_dollars(section) > 0)
	{
		args->size_malloc = count_dollars(section);
		args->start_pos = my_malloc(info, args->size_malloc * sizeof(int));
		if (args->start_pos == NULL)
		{
			fprintf(stderr, "Error allocating memory\n");
			exit(EXIT_FAILURE);
		}
		args->k = 0;
		while (args->k < args->size_malloc)
		{
			args->start_pos[args->k] = -1;
			args->k++;
		}
	}
}

void	ft_double_quote(const char *section, t_general *info, t_tokenargs *args)
{
	if (section[args->i] == '\"')
	{
		if (!args->in_single_quotes)
		{
			args->in_double_quotes = !args->in_double_quotes;
		}
		else
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
		args->i++;
	}
}

void	ft_single_quote(const char *section, t_general *info, t_tokenargs *args)
{
	if (section[args->i] == '\'')
	{
		if (!args->in_double_quotes)
		{
			args->in_single_quotes = !args->in_single_quotes;
		}
		else
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
		args->i++;
	}
}

void	ft_append(const char *section, t_general *info, t_tokenargs *args)
{
	if (section[args->i] == '>' && section[args->i + 1] == '>'
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
		add_token_to_list(info, ">>", APPEND);
		args->current_token = NULL;
		args->i++;
		args->expect_file = 1;
		args->is_first_token = 0;
		args->j = reset_positions(args->start_pos, args->size_malloc);
		args->j = 0;
	}
}
