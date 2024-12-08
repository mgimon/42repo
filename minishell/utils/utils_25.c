/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_25.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:34:00 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/01 20:03:30 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signals_print_handler(int print)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	if (print == 1)
	{
		term.c_lflag |= ECHOCTL;
	}
	tcsetattr(0, TCSANOW, &term);
}

void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_global_status = 130;
		write(1, "\n", 1);
		exit(130);
	}
	if (sig == SIGQUIT)
	{
		printf("heredoc_handler: SIGQUIT received\n");
		put_str_fd(2, "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		put_str_fd(2, "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b ");
		put_str_fd(2, "\b> \b");
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_global_status = 130;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	child_handler(int sig)
{
	if (sig == SIGINT)
	{
		put_str_fd(2, "\n");
		g_global_status = 130;
	}
	if (sig == SIGQUIT)
	{
		g_global_status = 131;
		put_str_fd(2, "Quit - core dumped \n");
	}
}

// Configura los manejadores de señales
void	setup_signals(int i)
{
	if (i == 0)
	{
		signals_print_handler(1);
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (i == 1)
	{
		signals_print_handler(0);
		signal(SIGINT, child_handler);
		signal(SIGQUIT, child_handler);
	}
	else if (i == 2)
	{
		signals_print_handler(0);
		signal(SIGINT, heredoc_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (i == 3)
	{
		signals_print_handler(0);
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
