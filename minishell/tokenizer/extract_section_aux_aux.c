/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_section_aux_aux.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:14:46 by albealva          #+#    #+#             */
/*   Updated: 2024/11/17 18:32:13 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_section_doble_input(const char *section, t_general *info,
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
			args->current_section, "<<");
	args->current_token = NULL;
	args->i++;
	args->j = reset_positions(args->start_pos, args->size_malloc);
	args->j = 0;
	args->quote_state = NONE;
}

void	ft_section_single_input(const char *section, t_general *info,
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
			args->current_section, "<");
	args->current_token = NULL;
	args->j = reset_positions(args->start_pos, args->size_malloc);
	args->j = 0;
	args->quote_state = NONE;
}

void	ft_section_trunc(const char *section, t_general *info,
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
			args->current_section, ">");
	args->current_token = NULL;
	args->j = reset_positions(args->start_pos, args->size_malloc);
	args->j = 0;
	args->quote_state = NONE;
}

void	ft_section_pipe(const char *section, t_general *info,
		t_section_args *args)
{
	if (args->current_token)
	{
		args->current_section = append_to_current_section(info,
				args->current_section, args->current_token);
		args->current_token = NULL;
		args->j = reset_positions(args->start_pos, args->size_malloc);
		args->j = 0;
		args->quote_state = NONE;
	}
	while (section[args->i] == '|')
	{
		args->current_section = append_to_current_section(info,
				args->current_section, "|");
		args->current_token = NULL;
		args->i++;
		args->j = reset_positions(args->start_pos, args->size_malloc);
		args->j = 0;
		args->quote_state = NONE;
	}
}

void	ft_section_args(const char *section, t_general *info,
		t_section_args *args)
{
	if (args->quote_state != SINGLE_QUOTE && count_dollars(section))
	{
		while (args->z < args->size_malloc && args->start_pos[args->z] != -1)
		{
			args->length_difference = calculate_length_difference(
					args->current_token, args->start_pos[args->z], info);
			args->current_token = expand_variable2(args->current_token,
					args->start_pos[args->z], info);
			while (args->h < args->size_malloc && args->start_pos[args->h]
				!= -1)
			{
				if (args->start_pos[args->h] + args->length_difference >= 0)
					args->start_pos[args->h] += args->length_difference;
				args->h++;
			}
			args->z++;
			args->h = 0;
		}
		args->z = 0;
	}
	ft_reset_section_state(args, info);
}
