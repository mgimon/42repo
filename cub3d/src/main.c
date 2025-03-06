/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/23 21:19:05 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_game(t_game *game)
{
	t_texture	*textures;

	textures = game->map->textures;
	game->mlx_window = mlx_new_window(game->mlx_connection, SCREEN_WITH,
			SCREEN_HIGH, "cub3D");
	game->img->img = mlx_new_image(game->mlx_connection, SCREEN_WITH,
			SCREEN_HIGH);
	game->img->addr = mlx_get_data_addr(game->img->img,
			&game->img->bits_per_pixel, &game->img->line_length,
			&game->img->endian);
	if (!init_texture(game, TEXTURE_SIZE))
		malloc_err();
	parse_texture(game, textures->path_no, 'N');
	parse_texture(game, textures->path_so, 'S');
	parse_texture(game, textures->path_ea, 'E');
	parse_texture(game, textures->path_we, 'W');
}

static void	start_game(t_game *game)
{
	render_frame(game);
	mlx_hook(game->mlx_window, 17, 0, handle_close, game);
	mlx_hook(game->mlx_window, 2, 1L << 0, handle_key, game);
	mlx_loop(game->mlx_connection);
}

// printline_fd(2, "\nThe map is valid\n\n");
int	parsing(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (printline_fd(2, "\nError: invalid arguments\n"), printline_fd(2,
				"You must provide a .cub map route as "), printline_fd(2,
				"only argument to the program\n\n"), 1);
	game->mlx_connection = mlx_init();
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		malloc_err();
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		malloc_err();
	if (get_map(game, argv[1]) == 1)
		return (2);
	if (check_map(game, game->map->matrix) == 0)
		init_resources(game, argv[1]);
	else
		return (printline_fd(2, "\nError: the map is invalid\n\n"),
			clean_close(game), 1);
	if (!is_map_last(game->map->cub))
	{
		printline_fd(2, "\nError: the map is invalid\n");
		printline_fd(2, "(Hint) Watch out for newlines at the end of file!\n");
		exit(1);
	}
	return (0);
}

void	inits(t_game *game)
{
	game->img = malloc(sizeof(t_imgdata));
	if (!game->img)
		malloc_err();
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		malloc_err();
	game->map->map = game->map->matrix;
	game->map->sizey = get_full_height(game->map->matrix);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		status;

	status = parsing(argc, argv, &game);
	if (status)
	{
		if (status == 2)
			free_parsing(&game);
		return (1);
	}
	inits(&game);
	init_game(&game);
	start_game(&game);
	clean_close(&game);
	free_structs(&game);
	return (0);
}
