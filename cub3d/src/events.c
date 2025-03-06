/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:05:57 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/22 21:04:32 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	move_player(t_game *game, int keycode)
{
	if (keycode == XK_w && !check_wall(game, keycode))
	{
		game->player->pos_y += game->player->dy * VELO_MOV;
		game->player->pos_x += game->player->dx * VELO_MOV;
	}
	if (keycode == XK_s && !check_wall(game, keycode))
	{
		game->player->pos_y -= game->player->dy * VELO_MOV;
		game->player->pos_x -= game->player->dx * VELO_MOV;
	}
	if (keycode == XK_a && !check_wall(game, keycode))
	{
		game->player->pos_y -= game->player->dx * VELO_MOV;
		game->player->pos_x += game->player->dy * VELO_MOV;
	}
	if (keycode == XK_d && !check_wall(game, keycode))
	{
		game->player->pos_y += game->player->dx * VELO_MOV;
		game->player->pos_x -= game->player->dy * VELO_MOV;
	}
	render_frame(game);
}

static void	rotate_player(t_game *game, int keycode)
{
	t_player	*player;

	player = game->player;
	if (keycode == XK_Right)
		rotate_r(player, player->dx, player->scr_dx);
	if (keycode == XK_Left)
		rotate_l(player, player->dx, player->scr_dx);
	render_frame(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_window);
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		exit(1);
	}
	if (keycode == XK_w || keycode == XK_s || keycode == XK_a
		|| keycode == XK_d)
		move_player(game, keycode);
	if (keycode == XK_Right || keycode == XK_Left)
		rotate_player(game, keycode);
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_display(game->mlx_connection);
	free(game->mlx_connection);
	exit(0);
	return (0);
}
