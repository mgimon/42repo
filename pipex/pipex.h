/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:26:53 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/12 20:54:42 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "ft_printf/ft_printf.h"

typedef struct s_struct
{
	char	**path;
	char	*path_cmd;

	char	**cmd;
	char	*filename;
	char	*argv2;
	char	*argv3;
	int		fd;
}	t_struct;

//	init.c
void	struct_init(t_struct *structure, char **argv,
			char **env, int which_cmd);
void	set_path(t_struct *structure, char **env);
void	set_cmd_in_path(t_struct *structure, char **env, char *cmd);
void	set_correct_path(t_struct *structure, int which_cmd);

//	process.c
void	pipex(t_struct *structure, char **argv, char **env);

//	utils.c
int		is_empty(char *argv);
int		ft_strlen_pipex(char const *str);
char	*ft_strjoin_pipex(char const *s1, char const *s2);
int		ft_strncmp_pipex(const char *str, const char *str2, size_t c);
void	matrix_free(char **s);

//  utils_two.c
void	error_free_close(t_struct *structure);
int		there_is_path(t_struct *structure);
int		no_path_or_absolute_cmd(t_struct *structure, int which_cmd);
void	set_values(t_struct *structure, char **argv, char **env, int which_cmd);

//	prints.c
void	print_arg(char *arg);
void	print_args(char **arg);

#endif
