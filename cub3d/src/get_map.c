/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:52:26 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/22 21:37:12 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*read_line(int fd)
{
	char	*line;
	int		i;
	int		bytes_read;

	line = malloc(256);
	if (!line)
		return (NULL);
	i = 0;
	bytes_read = read(fd, &line[i], 1);
	while (bytes_read > 0)
	{
		if (line[i] == '\n')
			break ;
		i++;
		bytes_read = read(fd, &line[i], 1);
	}
	if (bytes_read <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

void	init_map_textures(t_game *game)
{
	game->map->no_texture = malloc(sizeof(t_imgdata));
	if (!game->map->no_texture)
		malloc_err();
	game->map->so_texture = malloc(sizeof(t_imgdata));
	if (!game->map->so_texture)
		malloc_err();
	game->map->ea_texture = malloc(sizeof(t_imgdata));
	if (!game->map->ea_texture)
		malloc_err();
	game->map->we_texture = malloc(sizeof(t_imgdata));
	if (!game->map->we_texture)
		malloc_err();
}

int	store_map_line(t_game *game, char **result, int *k, char *line)
{
	result[*k] = ft_strdup(line);
	free(line);
	if (!result[*k])
	{
		while (--(*k) >= 0)
			free(result[*k]);
		free(result);
		close(game->map->fd);
		return (1);
	}
	(*k)++;
	return (0);
}

int	process_map_lines(t_game *game, char **result)
{
	int		k;
	char	*line;

	k = 0;
	line = read_line(game->map->fd);
	while (line != NULL)
	{
		if (is_map_line(line))
		{
			if (store_map_line(game, result, &k, line))
				return (1);
		}
		else
			free(line);
		line = read_line(game->map->fd);
	}
	result[k] = NULL;
	return (0);
}

int	get_map(t_game *game, char *filename)
{
	char	**result;
	int		map_size;

	map_size = get_mapsize(filename);
	game->map->cub = NULL;
	init_map_textures(game);
	game->map->fd = open(filename, O_RDONLY);
	if (game->map->fd < 0 || map_size <= 0 || !ends_with_cub(filename))
	{
		printline_fd(2, "Error: invalid file or invalid map size!\n");
		return (1);
	}
	result = malloc(sizeof(char *) * (map_size + 1));
	if (!result)
		return (close(game->map->fd), 1);
	if (process_map_lines(game, result))
		return (1);
	close(game->map->fd);
	game->map->matrix = result;
	return (0);
}
