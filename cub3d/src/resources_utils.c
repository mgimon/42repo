/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 03:36:00 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/23 21:20:00 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->matrix[i])
	{
		j = 0;
		while (game->map->matrix[i][j])
		{
			if (game->map->matrix[i][j] == 'N' || game->map->matrix[i][j] == 'S'
				|| game->map->matrix[i][j] == 'E'
				|| game->map->matrix[i][j] == 'W')
			{
				game->player->pos_x = (float)j + 0.5;
				game->player->pos_y = (float)i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	*extract_texture_path(char *line, char *prefix)
{
	int		j;
	char	*path;
	size_t	len;

	j = 0;
	while (line[j] == ' ' || line[j] == '\t')
		j++;
	if (ft_strncmp(&line[j], prefix, 2) == 0 && (line[j + 2] == ' ' || line[j
				+ 2] == '\t'))
	{
		j += 3;
		iterate_line(line, &j);
		path = ft_strdup(&line[j]);
		if (!path)
			return (NULL);
		len = ft_strlen(path);
		while (len > 0 && (path[len - 1] == ' ' || path[len - 1] == '\t'
				|| path[len - 1] == '\n'))
		{
			path[len - 1] = '\0';
			len--;
		}
		return (path);
	}
	return (NULL);
}

void	assign_texture(t_game *game, char *prefix, void *img_ptr)
{
	if (ft_strcmp(prefix, "NO") == 0)
		game->map->no_texture->img = img_ptr;
	else if (ft_strcmp(prefix, "SO") == 0)
		game->map->so_texture->img = img_ptr;
	else if (ft_strcmp(prefix, "WE") == 0)
		game->map->we_texture->img = img_ptr;
	else if (ft_strcmp(prefix, "EA") == 0)
		game->map->ea_texture->img = img_ptr;
}

void	load_texture(t_game *game, char *prefix, char *texture_path)
{
	int		width;
	int		height;
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx_connection, texture_path, &width,
			&height);
	if (!img_ptr)
	{
		printline_fd(2, "Error: mlx couldn't get one texture\n\n");
		printf("Texture path is: %s\n", texture_path);
		free(texture_path);
		return ;
	}
	assign_texture(game, prefix, img_ptr);
	if (ft_strcmp(prefix, "NO") == 0)
		game->map->textures->path_no = ft_strdup(texture_path);
	else if (ft_strcmp(prefix, "EA") == 0)
		game->map->textures->path_ea = ft_strdup(texture_path);
	else if (ft_strcmp(prefix, "WE") == 0)
		game->map->textures->path_we = ft_strdup(texture_path);
	else if (ft_strcmp(prefix, "SO") == 0)
		game->map->textures->path_so = ft_strdup(texture_path);
	free(texture_path);
}

void	get_texture(char *prefix, t_game *game)
{
	int		i;
	char	*texture_path;

	i = 0;
	while (game->map->cub[i] != NULL)
	{
		texture_path = extract_texture_path(game->map->cub[i], prefix);
		if (texture_path)
		{
			load_texture(game, prefix, texture_path);
			return ;
		}
		i++;
	}
	printline_fd(2, "Error: Texture prefix not found in .cub file\n");
}
