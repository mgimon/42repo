/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_section.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:43:10 by albealva          #+#    #+#             */
/*   Updated: 2024/11/17 20:05:38 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_finalize_section(const char *section, t_general *info,
		t_section_args *args)
{
	if (args->current_token)
		ft_section_args(section, info, args);
	if (args->current_section)
		trim_trailing_whitespace(args->current_section);
}

void	ft_handle_pipe_section(const char *section, t_general *info,
		t_section_args *args)
{
	if (args->current_token)
	{
		ft_section_args(section, info, args);
	}
	ft_section_pipe(section, info, args);
}

void	ft_initialize_section(const char *section, t_general *info,
		t_section_args *args)
{
	ft_init_section_args(args);
	ft_init_section(section, args, info);
}

void	handle_operators(const char *s, t_general *info, t_section_args *ar)
{
	if (s[ar->i] == '>' && s[ar->i + 1] == '>' && !ar->in_sq && !ar->in_dq)
		ft_section_append(s, info, ar);
	else if (s[ar->i] == '>' && s[ar->i + 1] != '>' && !ar->in_sq && !ar->in_dq)
		ft_section_trunc(s, info, ar);
	else if (s[ar->i] == '<' && s[ar->i + 1] == '<' && !ar->in_sq && !ar->in_dq)
		ft_section_doble_input(s, info, ar);
	else if (s[ar->i] == '<' && s[ar->i + 1] != '<' && !ar->in_sq && !ar->in_dq)
		ft_section_single_input(s, info, ar);
}

char	*extract_current_section(const char *s, t_general *info)
{
	t_section_args	ar;

	ft_initialize_section(s, info, &ar);
	while (s[ar.i] != '\0')
	{
		if (s[ar.i] == '\"' || s[ar.i] == '\'')
		{
			handle_quotes(s[ar.i], s, info, &ar);
			continue ;
		}
		else if (ft_it_is_operator(s[ar.i]))
			handle_operators(s, info, &ar);
		else if (s[ar.i] == '|' && !ar.in_sq && !ar.in_dq)
		{
			ft_handle_pipe_section(s, info, &ar);
			continue ;
		}
		else if (ft_isspace(s[ar.i]) && !ar.in_sq && !ar.in_dq)
			ft_handle_whitespace(s, info, &ar);
		else
			ft_handle_non_operator(s, info, &ar);
		ar.i++;
	}
	ft_finalize_section(s, info, &ar);
	return (ar.current_section);
}
/*
char	*extract_current_section(const char *section, t_general *info)
{
	t_section_args	args;

	ft_init_section_args(&args);
	ft_init_section(section,&args, info);
	while (section[args.i] != '\0')
	{
		if (section[args.i] == '\"')
		{
			ft_section_double_quotes(section, info, &args);
			continue ;
		}
		if (section[args.i] == '\'')
		{
			ft_section_single_quotes(section, info, &args);
			continue ;
		}
		if (section[args.i] == '>' && section[args.i + 1] == '>'
			&& !args.in_sq
			&& !args.in_dq)
			ft_section_append(section, info, &args);
		else if (section[args.i] == '>' && section[args.i + 1] != '>'
			&& !args.in_sq
			&& !args.in_dq)
			ft_section_trunc(section, info, &args);
		else if (section[args.i] == '<' && section[args.i + 1] == '<'
			&& !args.in_sq
			&& !args.in_dq)
		{
			ft_section_doble_input(section, info, &args);
		}
		else if (section[args.i] == '<' && section[args.i + 1] != '<'
			&& !args.in_sq
			&& !args.in_dq)
			ft_section_single_input(section, info, &args);
		else if (section[args.i] == '|' && !args.in_sq
			&& !args.in_dq)
		{
			if (args.current_token)
				ft_section_args(section, info, &args);
			ft_section_pipe(section, info, &args);
			continue ;
		}
		else if (ft_isspace(section[args.i]) && !args.in_sq
			&& !args.in_dq)
		{
			if (args.current_token)
			{
				ft_section_args(section, info, &args);
			}
		}
		else
		{
			args.current_token = add_char_to_token2(info, args.current_token,
					section[args.i]);
			if (section[args.i] == '$' && !args.in_sq
				&& args.current_token)
			{
				args.start_pos[args.j] = ft_strlen(args.current_token);
				args.j++;
			}
		}
		args.i++;
	}
	if (args.current_token)
	{
		ft_section_args(section, info, &args);
	}
	if (args.current_section)
		trim_trailing_whitespace(args.current_section);
	return (args.current_section);
}
*/

/*

char	*extract_current_section(const char *s, t_general *info)
{
	t_section_args	ar;

	ft_initialize_section(s, info, &ar);
	while (s[ar.i] != '\0')
	{
		if (s[ar.i] == '\"' || s[ar.i] == '\'')
			handle_quotes(s[ar.i], s, info, &ar);
			//ft_section_double_quotes(s, info, &ar);
		else if (s[ar.i] == '>' && s[ar.i + 1] == '>' && !ar.in_sq && !ar.in_dq)
			ft_section_append(s, info, &ar);
		else if (s[ar.i] == '>' && s[ar.i + 1] != '>' && !ar.in_sq && !ar.in_dq)
			ft_section_trunc(s, info, &ar);
		else if (s[ar.i] == '<' && s[ar.i + 1] == '<' && !ar.in_sq && !ar.in_dq)
			ft_section_doble_input(s, info, &ar);
		else if (s[ar.i] == '<' && s[ar.i + 1] != '<' && !ar.in_sq && !ar.in_dq)
			ft_section_single_input(s, info, &ar);
		else if (s[ar.i] == '|' && !ar.in_sq && !ar.in_dq)
			ft_handle_pipe_section(s, info, &ar);
		else if (ft_isspace(s[ar.i]) && !ar.in_sq && !ar.in_dq)
			ft_handle_whitespace(s, info, &ar);
		else
			ft_handle_non_operator(s, info, &ar);
		ar.i++;
	}
	ft_finalize_section(s, info, &ar);
	return (ar.current_section);
}

*/
