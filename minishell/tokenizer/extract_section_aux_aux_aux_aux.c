/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_section_aux_aux_aux_aux.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:33:24 by albealva          #+#    #+#             */
/*   Updated: 2024/11/17 19:45:47 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_while_pipe(const char *section, t_general *info,
		t_section_args *args)
{
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

void	handle_quotes(const char c, const char *section, t_general *info,
		t_section_args *args)
{
	if (c == '\"')
	{
		ft_section_double_quotes(section, info, args);
	}
	if (c == '\'')
	{
		ft_section_single_quotes(section, info, args);
	}
}

int	ft_it_is_operator(const char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

void	ft_handle_non_operator(const char *section, t_general *info,
		t_section_args *args)
{
	args->current_token = add_char_to_token2(info, args->current_token,
			section[args->i]);
	if (section[args->i] == '$' && !args->in_sq && args->current_token)
	{
		args->start_pos[args->j] = ft_strlen(args->current_token);
		args->j++;
	}
}

void	ft_handle_whitespace(const char *section, t_general *info,
		t_section_args *args)
{
	if (args->current_token)
		ft_section_args(section, info, args);
}
