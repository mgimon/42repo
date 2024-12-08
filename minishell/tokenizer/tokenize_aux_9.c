/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_aux_9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:19:43 by albealva          #+#    #+#             */
/*   Updated: 2024/11/15 18:39:53 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	capture_and_expand_variable(const char *input, t_general *info,
		t_args *args)
{
	capture_var_and_value(input, info, args);
	if (args->value)
		handle_expansion_chars(args, args->value);
	args->expanded = 1;
}

void	handle_dollar_one(const char *input, t_general *info, t_args *args)
{
	if (input[args->i + 1] == '?' && !args->expanded)
	{
		handle_expand_dollar_question(info, args);
	}
	else if (input[args->i + 1] == '0' && !args->expanded)
	{
		handle_expand_dollar_zero(args);
	}
	else if (input[args->i + 1] >= '1' && input[args->i + 1] <= '9'
		&& !args->expanded)
	{
		ft_line(args);
	}
}

void	ft_fnt(const char *input, t_general *info, t_args *args)
{
	if (input[args->i] == '$' && (input[args->i + 1] == '?' || input[args->i
				+ 1] == '0' || (input[args->i + 1] >= '1' && input[args->i
					+ 1] <= '9')) && !args->expanded)
	{
		handle_dollar_one(input, info, args);
		return ;
	}
	if (input[args->i] == '$' && !args->expanded)
	{
		args->i++;
		if (args->i >= args->len || !(ft_isalnum(input[args->i])
				|| input[args->i] == '_'))
		{
			copy_invalid_char_to_temp(args, input, &args->i);
			return ;
		}
		capture_and_expand_variable(input, info, args);
	}
	else
	{
		args->temp[args->temp_index++] = input[args->i];
	}
}

char	*expand_variable2(const char *input, int start_pos, t_general *info)
{
	t_args	args;

	initialize_and_copy_args(&args, input, start_pos);
	while (args.i++ < args.len)
	{
		ft_fnt(input, info, &args);
	}
	args.resul = trolft_strdup(args.temp, info);
	return (args.resul);
}

int	calculate_length_difference(const char *input, int start_pos,
		t_general *info)
{
	int	original_len;
	int	length_difference;
	int	expanded_len;

	original_len = ft_strlen(input);
	expanded_len = strlen(expand_variable2(input, start_pos, info));
	length_difference = expanded_len - original_len;
	return (length_difference);
}
