/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:26:16 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/08 19:49:53 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

int		g_global_status = 0;

// Inicializa la estructura general
int	init_general(t_general *info, char **env)
{
	info->number_of_tokens = 0;
	info->tokens_list = NULL;
	info->env = env;
	return (0);
}

// Inicializa el historial de comandos
void	init_history(const char *history_file)
{
	using_history();
	if (access(history_file, F_OK) == 0)
		read_history(history_file);
}

// Guarda el historial al final del programa
void	cleanup(const char *history_file)
{
	write_history(history_file);
}

int	limtit_input(char *input)
{
	if (input != NULL)
	{
		if (ft_strlen(input) > 2890)
		{
			printf("Error: prompt limit exceeded:\n");
			input[2890] = '\0';
			return (1);
		}
	}
	return (0);
}

/*if (input && has_content(input) && !limtit_input(input))
{
	if (open_quote(input, &state) != 0)
	{
		free(input);
		input = NULL;
		continue ;
	}
	handle_input(&info, input, &print_mode);
	if (check_syntax_errors(&info) == 1)
	{
		free(input);
		input = NULL;
		continue ;
	}
	routine(&info, &input);
}*/
int	main(int argc, char **argv, char **env)
{
	char			*input;
	t_general		info;
	const char		*history_file = ".minishell_history";
	int				print_mode;
	t_quote_state	state;

	(void)argc;
	(void)argv;
	inits_inits(&info, &env, &history_file, &print_mode);
	while (1)
	{
		setup_signals(0);
		input = readline("mini> ");
		if (g_global_status != 0)
			info.exit_status = g_global_status;
		if (!check_input(&info, &input))
			break ;
		do_your_thing(&info, &input, &state, &print_mode);
		if (info.null_paths == 1)
			info.paths = NULL;
	}
	return (finish(&info, &history_file, &input), 0);
}
