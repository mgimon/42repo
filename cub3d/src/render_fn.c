/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:55:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/23 21:12:39 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	img_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	*(int *)pixel = color;
}

void	paint_window(t_game *game, int color)
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;

	size_x = SCREEN_WITH;
	size_y = SCREEN_HIGH;
	x = 0;
	while (x < size_x)
	{
		y = 0;
		while (y < size_y)
		{
			img_pixel_put(game->img, x, y, color);
			y++;
		}
		x++;
	}
}

void	render_frame(t_game *game)
{
	paint_window(game, GREY);
	draw_rays(game);
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
		game->img->img, 0, 0);
}

static void	check_height(int *start_y, int *end)
{
	if (*start_y < 0)
		*start_y = 0;
	if (*end > SCREEN_HIGH)
		*end = SCREEN_HIGH - 1;
}

void	draw_walls(t_game *game, int column, t_ray *ray)
{
	int	heigh;
	int	start_y;
	int	end;
	int	**texture;
	int	texure_y;

	texture = select_tetxture(game, ray);
	heigh = ((SCREEN_HIGH / ray->distance) * 0.5);
	start_y = (SCREEN_HIGH / 2) - (heigh / 2);
	end = start_y + heigh;
	check_height(&start_y, &end);
	paint_sky(game, start_y, column);
	while (start_y < end)
	{
		texure_y = (int)((start_y - SCREEN_HIGH / 2 + heigh / 2)
				* (1.0 * TEXTURE_SIZE / heigh));
		img_pixel_put(game->img, column, start_y,
			texture[texure_y][ray->texture_pixel]);
		start_y++;
	}
	paint_floor(game, start_y, column);
}
