/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_section_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:09:22 by albealva          #+#    #+#             */
/*   Updated: 2024/11/17 18:12:57 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_init_section_args(t_section_args *args)
{
	args->i = 0;
	args->in_sq = 0;
	args->in_dq = 0;
	args->quote_state = NONE;
	args->start_pos = NULL;
	args->j = 0;
	args->z = 0;
	args->length_difference = 0;
	args->h = 0;
	args->current_section = NULL;
	args->current_token = NULL;
}

void	ft_init_section(const char *section, t_section_args *args,
		t_general *info)
{
	int	k;

	k = 0;
	if (section && count_dollars(section) > 0)
	{
		args->size_malloc = count_dollars(section);
		args->start_pos = my_malloc(info, args->size_malloc * sizeof(int));
		if (args->start_pos == NULL)
		{
			printf("Error allocating memory\n");
			exit(EXIT_FAILURE);
		}
		while (k < args->size_malloc)
		{
			args->start_pos[k] = -1;
			k++;
		}
	}
}

void	ft_section_double_quotes(const char *section, t_general *info,
		t_section_args *args)
{
	if (!args->in_sq)
	{
		args->in_dq = !args->in_dq;
		if (args->in_dq)
		{
			args->quote_state = DOUBLE_QUOTE;
		}
		args->current_token = add_char_to_token2(info, args->current_token,
				section[args->i]);
	}
	else
	{
		args->current_token = add_char_to_token2(info, args->current_token,
				section[args->i]);
		if (section[args->i] == '$' && !args->in_sq && args->current_token)
		{
			args->start_pos[args->j] = ft_strlen(args->current_token);
			args->j++;
		}
	}
	args->i++;
}

void	ft_section_single_quotes(const char *section, t_general *info,
		t_section_args *args)
{
	if (!args->in_dq)
	{
		args->in_sq = !args->in_sq;
		if (args->in_sq)
		{
			args->quote_state = SINGLE_QUOTE;
		}
		args->current_token = add_char_to_token2(info, args->current_token,
				section[args->i]);
	}
	else
	{
		args->current_token = add_char_to_token2(info, args->current_token,
				section[args->i]);
		if (section[args->i] == '$' && !args->in_sq && args->current_token)
		{
			args->start_pos[args->j] = ft_strlen(args->current_token);
			args->j++;
		}
	}
	args->i++;
}

void	ft_section_append(const char *section, t_general *info,
		t_section_args *args)
{
	(void)section;
	if (args->current_token)
	{
		args->current_section = append_to_current_section(info,
				args->current_section, args->current_token);
		args->current_token = NULL;
		args->j = reset_positions(args->start_pos, args->size_malloc);
		args->j = 0;
		args->quote_state = NONE;
	}
	args->current_section = append_to_current_section(info,
			args->current_section, ">>");
	args->current_token = NULL;
	args->i++;
	args->j = reset_positions(args->start_pos, args->size_malloc);
	args->j = 0;
	args->quote_state = NONE;
}
