/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_aux_expansor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:16:26 by albealva          #+#    #+#             */
/*   Updated: 2024/11/15 18:17:20 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	capture_var_name(const char *input, int *i, t_args *args)
{
	while (*i < args->len && !is_special_separator(input[*i])
		&& (ft_isalnum(input[*i]) || input[*i] == '_'))
	{
		args->var_name[args->var_index++] = input[*i];
		(*i)++;
	}
	args->var_name[args->var_index] = '\0';
}

void	handle_expansion_chars(t_args *args, const char *value)
{
	int	k;

	k = 0;
	while (value[k] != '\0')
	{
		if (value[k] == '"' || value[k] == '\'' || value[k] == '$')
		{
			args->temp[args->temp_index++] = mark_char(value[k]);
		}
		else
		{
			args->temp[args->temp_index++] = value[k];
		}
		k++;
	}
}

void	initialize_and_copy_args(t_args *args, const char *input, int start_pos)
{
	ft_initialize_args(args, input, start_pos);
	ft_copy_initial_chars(input, start_pos, args);
}

void	capture_var_and_value(const char *input, t_general *info, t_args *args)
{
	args->var_index = 0;
	capture_var_name(input, &args->i, args);
	args->i--;
	args->value = get_env_var(info, args->var_name);
}

void	ft_line(t_args *args)
{
	args->i++;
	args->expanded = 1;
}
