/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:26:53 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/02 17:48:15 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_struct
{
	char	**path;
	char	*path_cmd1;
	char	*path_cmd2;

	char	*cmd1;
	char	*cmd2;
	char	*filename1;
	char	*filename2;

	int		file1;
	int		file2;
}	t_struct;

//	main.c

//	utils.c
int		ft_strlen_pipex(char const *str);
char	*ft_strjoin_pipex(char const *s1, char const *s2);
int		ft_strncmp_pipex(const char *str, const char *str2, size_t c);
void	matrix_free(char **s);


//	prints.c
void	print_arg(char *arg);
void	print_args(char **arg);

//	init.c
void	set_cmd_in_path(t_struct *structure, char **env, char *cmd);
void	struct_init(t_struct *structure, char **argv, char **env);

#endif
