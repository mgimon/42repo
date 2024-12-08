/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_27.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:36:11 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/02 20:09:56 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	inits_inits(t_general *info, char ***env, const char **history_file,
		int *print_mode)
{
	*print_mode = 1;
	g_global_status = 0;
	init_general(info, *env);
	init_history(*history_file);
	set_paths_and_env(info, *env);
}

void	finish(t_general *info, const char **history_file, char **input)
{
	write_history(*history_file);
	free(*input);
	*input = NULL;
	free_all_allocated_blocks(info);
}

int	check_input(t_general *info, char **input)
{
	if (!(*input))
	{
		matrix_free(info->paths);
		matrix_free(info->exports);
		matrix_free(info->env);
		put_str_fd(2, "exit\n");
		return (0);
	}
	return (1);
}

void	do_your_thing(t_general *info, char **input, t_quote_state *state,
		int *print_mode)
{
	if (*input && has_content(*input) && !limtit_input(*input))
	{
		if (open_quote(*input, state) != 0)
		{
			free(*input);
			*input = NULL;
			return ;
		}
		handle_input(info, *input, print_mode);
		if (check_syntax_errors(info) == 1)
		{
			free(*input);
			*input = NULL;
			return ;
		}
		routine(info, &(*input));
	}
	free(*input);
	*input = NULL;
}

void	initialize_ij(int *i, int *j)
{
	*i = 0;
	*j = 0;
}
