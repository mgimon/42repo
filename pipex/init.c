/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:08:34 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/07 19:50:41 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//inits structure->path to env
void	set_path(t_struct *structure, char **env)
{
	int	i;
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
			matrix_free(structure->path);
		structure->path = ft_split(tmp, ':');
		if (structure->path == NULL)
		{
			free(structure->cmd[0]);
			close(structure->fd);
			perror("Error");
			exit(1);
		}
	}
}

//adds /cmd to structure->path
void	set_cmd_in_path(t_struct *structure, char **env, char *cmd)
{
	char	*new_path;
	int	i;

	if (!structure)
		return ;
	i = 0;
	set_path(structure, env);
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
			free(structure->cmd[0]);
                        close(structure->fd);
			perror("Error");
			exit(1);
		}
		free(structure->path[i]);
		structure->path[i] = new_path;
		i++;
	}
}

//sets structure->path_cmd to the first accessible path
void	set_correct_path(t_struct *structure)
{
	int	i;

	i = 0;
	while (structure->path[i] != NULL)
	{
		if (access(structure->path[i], R_OK) == 0)
		{
			structure->path_cmd = ft_strdup(structure->path[i]);
			return ;
		}
		i++;
	}
	// error - ninguna ruta valida
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
		//error management
		perror("");
		exit(1);
	}
	structure->fd = fd;
}

void	struct_init(t_struct *structure, char **argv, char **env, int which_cmd)
{
	char	**cmd;

	if (which_cmd == 1)
		structure->filename = argv[1];
	else if (which_cmd == 2)
		structure->filename = argv[4];	
	open_file(structure, which_cmd);
	if (which_cmd == 1)
	{
		structure->filename = argv[1];
		cmd = ft_split(argv[2], ' ');
		cmd[0] = ft_strjoin("/", cmd[0]);
	}
	else if (which_cmd == 2)
	{
		structure->filename = argv[4];
		cmd = ft_split(argv[3], ' ');
		cmd[0] = ft_strjoin("/", cmd[0]);
	}
	structure->cmd = cmd;
	structure->path = NULL;
	structure->path_cmd = NULL;
	set_cmd_in_path(structure, env, structure->cmd[0]);
	set_correct_path(structure);
}
