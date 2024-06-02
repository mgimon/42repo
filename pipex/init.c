/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:08:34 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/02 19:04:12 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//inits structure->path to env
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
			matrix_free(structure->path);
		structure->path = ft_split(tmp, ':');
		if (structure->path == NULL)
		{
			free(structure->cmd1);
			free(structure->cmd2);
			perror("Error");
			exit(1);
		}
	}
}

//adds one /cmd to structure->path
void	set_cmd_in_path(t_struct *structure, char **env, char *cmd)
{
	char	*new_path;
	int		i;

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
			free(structure->cmd1);
			free(structure->cmd2);
			perror("Error");
			exit(1);
		}
		free(structure->path[i]);
		structure->path[i] = new_path;
		i++;
	}
}

//sets structure->path_cmd1 to the first accessible path
//or
//sets structure->path_cmd2 to the first accessible path
void	set_correct_path(t_struct *structure, int which_cmd)
{
	int	i;

	i = 0;
	while (structure->path[i] != NULL)
	{
		if (access(structure->path[i], R_OK) == 0)
		{
			if (which_cmd == 1)
			{
				structure->path_cmd1 = ft_strdup(structure->path[i]);
				return ;
			}
			if (which_cmd == 2)
			{
				structure->path_cmd2 = ft_strdup(structure->path[i]);
				return ;
			}
		}
		i++;
	}
}

void	struct_init(t_struct *structure, char **argv, char **env)
{
	char	*cmd1;
	char	*cmd2;

	cmd1 = NULL;
	cmd2 = NULL;
	cmd1 = ft_strjoin_pipex("/", argv[2]);
	if (cmd1 == NULL)
	{
		perror("Error");
		exit(1);
	}
	cmd2 = ft_strjoin_pipex("/", argv[3]);
	if (cmd2 == NULL)
	{	
		perror("Error");
		free(cmd1);
		exit(1);
	}
	structure->cmd1 = cmd1;
	structure->cmd2 = cmd2;
	structure->filename1 = argv[1];
	structure->filename2 = argv[4];
	structure->path = NULL;
	structure->path_cmd1 = NULL;
	structure->path_cmd2 = NULL;
	set_cmd_in_path(structure, env, structure->cmd1);
	set_correct_path(structure, 1);
	set_cmd_in_path(structure, env, structure->cmd2);
	set_correct_path(structure, 2);
}
