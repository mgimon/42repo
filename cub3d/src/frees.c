/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 04:56:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/22 21:28:39 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_parsing(t_game *game)
{
	free(game->map->ea_texture);
	free(game->map->no_texture);
	free(game->map->so_texture);
	free(game->map->we_texture);
	free(game->map);
	free(game->player);
	free(game->mlx_connection);
}

void	free_destroy_parsing(t_game *game)
{
	free(game->map->cub);
	free(game->map->no_texture);
	free(game->map->ea_texture);
	free(game->map->we_texture);
	free(game->map->so_texture);
	free(game->map);
	free(game->player);
	if (game->mlx_connection)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
	}
}

void	clean_close(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->matrix[i])
	{
		free(game->map->matrix[i]);
		i++;
	}
	free(game->map->matrix);
	i = 0;
	if (game->map->cub)
	{
		while (game->map->cub[i])
		{
			free(game->map->cub[i]);
			i++;
		}
	}
	free_destroy_parsing(game);
}

void	error_exit(char *msg, int exit_code, t_game *game)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (game->map != NULL)
		free(game->map);
	if (game->player != NULL)
		free(game->player);
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_display(game->mlx_connection);
	free(game->mlx_connection);
	exit(exit_code);
}

void	free_structs(t_game *game)
{
	free(game->img);
	free(game->player);
	free(game->ray);
}
