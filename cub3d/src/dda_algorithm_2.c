/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:01:26 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/22 21:09:35 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	texture_x_coord(t_ray *ray)
{
	float	endpoint;

	if (ray->side == 0)
	{
		endpoint = ray->camera_pos[1] + ray->distance * ray->ray_dir[1];
		endpoint -= floor(endpoint);
		ray->texture_pixel = endpoint * (double)TEXTURE_SIZE;
		if (ray->ray_dir[0] > 0)
			ray->texture_pixel = TEXTURE_SIZE - ray->texture_pixel - 1;
	}
	else
	{
		endpoint = ray->camera_pos[0] + ray->distance * ray->ray_dir[0];
		endpoint -= floor(endpoint);
		ray->texture_pixel = (int)(endpoint * TEXTURE_SIZE) % TEXTURE_SIZE;
		ray->texture_pixel = endpoint * (double)TEXTURE_SIZE;
		if (ray->ray_dir[1] < 0)
			ray->texture_pixel = TEXTURE_SIZE - ray->texture_pixel - 1;
	}
}

int	is_wall(char **mapa, int x, int y)
{
	if (mapa[y][x] == '1')
		return (1);
	return (0);
}
