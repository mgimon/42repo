/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:18:32 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/22 21:03:03 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_ray(t_game *game, int pixel)
{
	t_ray	*ray;

	ray = game->ray;
	ray->camera_pos[0] = game->player->pos_x;
	ray->camera_pos[1] = game->player->pos_y;
	ray->camara_dx = 2 * pixel / (double)SCREEN_WITH - 1;
	ray->ray_dir[0] = game->player->dx + game->player->scr_dx * ray->camara_dx
		* -1;
	ray->ray_dir[1] = game->player->dy + game->player->scr_dy * ray->camara_dx
		* -1;
	ray->map_pos[0] = (int)game->player->pos_x;
	ray->map_pos[1] = (int)game->player->pos_y;
	ray->side_dis_x = fabs(1 / ray->ray_dir[0]);
	ray->side_dis_y = fabs(1 / ray->ray_dir[1]);
}

static void	setup_ray(t_ray *ray)
{
	if (ray->ray_dir[0] < 0)
	{
		ray->stepx = -1;
		ray->delta_dis_x = (ray->camera_pos[0] - ray->map_pos[0])
			* ray->side_dis_x;
	}
	else
	{
		ray->stepx = 1;
		ray->delta_dis_x = (ray->map_pos[0] + 1 - ray->camera_pos[0])
			* ray->side_dis_x;
	}
	if (ray->ray_dir[1] < 0)
	{
		ray->stepy = -1;
		ray->delta_dis_y = (ray->camera_pos[1] - ray->map_pos[1])
			* ray->side_dis_y;
	}
	else
	{
		ray->stepy = 1;
		ray->delta_dis_y = (ray->map_pos[1] + 1 - ray->camera_pos[1])
			* ray->side_dis_y;
	}
}

void	run_dda_al(t_ray *ray, char **map)
{
	while (!is_wall(map, ray->map_pos[0], ray->map_pos[1]))
	{
		if (ray->delta_dis_x < ray->delta_dis_y)
		{
			ray->map_pos[0] += ray->stepx;
			ray->delta_dis_x += ray->side_dis_x;
			ray->side = 0;
		}
		else
		{
			ray->map_pos[1] += ray->stepy;
			ray->delta_dis_y += ray->side_dis_y;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->distance = ray->delta_dis_x - ray->side_dis_x;
	else
		ray->distance = ray->delta_dis_y - ray->side_dis_y;
}

void	draw_rays(t_game *game)
{
	t_ray	*ray;
	int		pixel_w;

	ray = game->ray;
	pixel_w = 0;
	while (pixel_w < SCREEN_WITH)
	{
		init_ray(game, pixel_w);
		setup_ray(ray);
		run_dda_al(ray, game->map->map);
		texture_x_coord(ray);
		draw_walls(game, pixel_w, ray);
		pixel_w++;
	}
}

int	**select_tetxture(t_game *game, t_ray *ray)
{
	t_texture	*textures;
	int			**texture;

	textures = game->map->textures;
	if (ray->side == 0)
	{
		if (ray->ray_dir[0] < 0)
			texture = textures->texture_we;
		else
			texture = textures->texture_ea;
	}
	else
	{
		if (ray->ray_dir[1] < 0)
			texture = textures->texture_no;
		else
			texture = textures->texture_so;
	}
	return (texture);
}
