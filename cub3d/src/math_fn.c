/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:25:55 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/22 21:50:06 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_player_dir(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player->dx = 0;
		game->player->dy = -1 * 1;
	}
	if (dir == 'S')
	{
		game->player->dx = 0;
		game->player->dy = -1 * -1;
	}
	if (dir == 'E')
	{
		game->player->dx = 1;
		game->player->dy = -1 * 0;
	}
	if (dir == 'W')
	{
		game->player->dx = -1;
		game->player->dy = -1 * 0;
	}
	game->player->scr_dx = game->player->dy * 0.66;
	game->player->scr_dy = game->player->dx * -1 * 0.66;
}
