/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_expansor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:12:01 by albealva          #+#    #+#             */
/*   Updated: 2024/11/15 18:15:02 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_initialize_args(t_args *args, const char *input, int start_pos)
{
	args->resul = NULL;
	args->len = strlen(input);
	ft_memset(args->temp, 0, sizeof(args->temp));
	ft_memset(args->var_name, 0, sizeof(args->var_name));
	args->temp_index = 0;
	args->var_index = 0;
	args->expanded = 0;
	args->i = start_pos - 2;
	args->value = NULL;
}

void	ft_copy_initial_chars(const char *input, int start_pos, t_args *args)
{
	int	i;

	i = 0;
	if (start_pos == 0)
		args->temp[args->temp_index++] = input[0];
	while (i < start_pos - 1)
	{
		args->temp[args->temp_index++] = input[i];
		i++;
	}
}

void	handle_expand_dollar_question(t_general *info, t_args *args)
{
	args->i++;
	args->exit_status_str = expand_dollar_question(info);
	if (args->exit_status_str != NULL)
	{
		ft_strcpy(args->temp + args->temp_index, args->exit_status_str);
		args->temp_index += ft_strlen(args->exit_status_str);
	}
	args->expanded = 1;
}

void	handle_expand_dollar_zero(t_args *args)
{
	ft_strcpy(args->temp + args->temp_index, "minishell");
	args->temp_index += ft_strlen("minishell");
	args->expanded = 1;
	args->i++;
}

void	copy_invalid_char_to_temp(t_args *args, const char *input, int *i)
{
	args->temp[args->temp_index++] = '$';
	if (*i < args->len)
	{
		args->temp[args->temp_index++] = input[*i];
	}
	args->expanded = 1;
}
