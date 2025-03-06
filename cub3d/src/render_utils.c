/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:35:22 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/22 21:52:25 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	paint_sky(t_game *game, int start_y, int column)
{
	int	n;

	n = 0;
	while (n < start_y)
	{
		img_pixel_put(game->img, column, n, game->map->ceiling);
		n++;
	}
}

void	paint_floor(t_game *game, int start_y, int column)
{
	while (start_y < SCREEN_HIGH)
	{
		img_pixel_put(game->img, column, start_y, game->map->floor);
		start_y++;
	}
}
