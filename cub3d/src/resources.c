/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:04:09 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/22 21:57:04 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_cub(t_game *game, char *filename)
{
	size_t	count;
	size_t	capacity;

	count = 0;
	capacity = 10;
	game->map->fd = open(filename, O_RDONLY);
	if (game->map->fd < 0)
	{
		printf("Failed to open file\n");
		return ;
	}
	game->map->cub = malloc(sizeof(char *) * capacity);
	if (!game->map->cub)
		malloc_err();
	read_cub_file(game, &count, &capacity);
	game->map->cub[count] = NULL;
	close(game->map->fd);
}

int	get_hex_from_cubline(char *line)
{
	int	i;
	int	ci;
	int	colors[3];

	i = 0;
	ci = 0;
	iterate_line(line, &i);
	if ((line[i] != 'C' && line[i] != 'F') || line[i + 1] != ' ')
		return (-1);
	i += 2;
	while (line[i] && ci < 3)
	{
		iterate_line(line, &i);
		if (!ft_isdigit(line[i]))
			return (-1);
		colors[ci] = parse_color_component(line, &i);
		if (colors[ci] == -1)
			return (-1);
		if (ci < 2 && line[i++] != ',')
			return (-1);
		ci++;
	}
	if (validate_color_line(line, i) == -1)
		return (-1);
	return ((colors[0] << 16) | (colors[1] << 8) | colors[2]);
}

static void	load_textures(t_game *game)
{
	game->map->textures = malloc(sizeof(t_texture));
	if (!game->map->textures)
		malloc_err();
	get_texture("NO", game);
	get_texture("EA", game);
	get_texture("WE", game);
	get_texture("SO", game);
}

static void	process_cub_lines(t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	while (game->map->cub[i] != NULL)
	{
		line = game->map->cub[i];
		while (*line == ' ' || *line == '\t')
			line++;
		if (line[0] == 'C' || line[0] == 'F')
			parse_colors(game, line);
		i++;
	}
}

void	init_resources(t_game *game, char *filename)
{
	game->map->ceiling = -1;
	game->map->floor = -1;
	get_cub(game, filename);
	if (!game->map->cub)
		exit(1);
	process_cub_lines(game);
	if (game->map->ceiling == -1 || game->map->floor == -1)
	{
		printf("\nError: One or more colors not found\n\n");
		exit(1);
	}
	game->map->sizey = get_full_height(game->map->matrix);
	game->map->sizex = get_full_width(game->map->matrix);
	set_player_pos(game);
	load_textures(game);
}
