/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:26:53 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/07 19:27:37 by mgimon-c         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_struct
{
	char	**path;
	char	*path_cmd;

	char	**cmd;
	char	*filename;
	char	*argv2;
	char	*argv3;
	int	fd;
}	t_struct;


//      init.c
void    struct_init(t_struct *structure, char **argv, char **env, int which_cmd);

//      process.c
void    pipex(t_struct *structure, char **argv, char **env);

//	utils.c
int	ft_strlen_pipex(char const *str);
char	*ft_strjoin_pipex(char const *s1, char const *s2);
int	ft_strncmp_pipex(const char *str, const char *str2, size_t c);
void	matrix_free(char **s);

//	prints.c
void	print_arg(char *arg);
void	print_args(char **arg);

#endif
