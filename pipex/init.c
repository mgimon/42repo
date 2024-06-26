/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:08:34 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/12 20:54:39 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//inits structure->path to env.
//if no 'PATH=', it remains NULL
void	set_path(t_struct *structure, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp_pipex(env[i], "PATH=", 5) == 0)
		{
			tmp = env[i];
			break ;
		}
		i++;
	}
	if (tmp)
	{
		if (structure->path != NULL)
		{
			matrix_free(structure->path);
			structure->path = NULL;
		}
		structure->path = ft_split(tmp, ':');
		if (structure->path == NULL)
			error_free_close(structure);
	}
}

//adds /cmd to structure->path
//if no 'PATH=', it does nothing
void	set_cmd_in_path(t_struct *structure, char **env, char *cmd)
{
	char	*new_path;
	int		i;

	i = 0;
	set_path(structure, env);
	if (structure->path)
	{
		while (structure->path[i] != NULL)
		{
			new_path = ft_strjoin_pipex(structure->path[i], cmd);
			if (new_path == NULL)
			{
				while (i >= 0)
				{
					free(structure->path[i]);
					i--;
				}
				free(structure->path);
				error_free_close(structure);
			}
			free(structure->path[i]);
			structure->path[i] = new_path;
			i++;
		}
	}
}

//sets structure->path_cmd to the first accessible path
//if no 'PATH=', it sets it to argv[2]/argv[3] if accessible
//exit error values are implemented to mimic shell behavior
void	set_correct_path(t_struct *structure, int which_cmd)
{
	int	stop;

	stop = 0;
	if (structure->path)
		stop = there_is_path(structure);
	else
		stop = no_path_or_absolute_cmd(structure, which_cmd);
	if (stop > 0)
		return ;
	matrix_free(structure->path);
	matrix_free(structure->cmd);
	close(structure->fd);
	write(2, "Error: command not found\n", 25);
	if (which_cmd == 1)
		exit(1);
	else
		exit(127);
}

void	open_file(t_struct *structure, int which_cmd)
{
	int	fd;

	if (which_cmd == 1)
		fd = open(structure->filename, O_RDONLY);
	else if (which_cmd == 2)
		fd = open(structure->filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		perror("Error");
		exit(1);
	}
	structure->fd = fd;
}

void	struct_init(t_struct *structure, char **argv, char **env, int which_cmd)
{
	if (which_cmd == 1)
		structure->filename = argv[1];
	else if (which_cmd == 2)
		structure->filename = argv[4];
	open_file(structure, which_cmd);
	if ((argv[2][0] == '\0') | (argv[3][0] == '\0'))
	{
		write(2, "Error: permission denied\n", 25);
		close(structure->fd);
		exit(126);
	}
	if (is_empty(argv[2]) == 1 && is_empty(argv[3]) == 1)
	{
		write(2, "Error: command not found\n", 25);
		close(structure->fd);
		exit(127);
	}
	structure->path = NULL;
	structure->path_cmd = NULL;
	set_values(structure, argv, env, which_cmd);
}
