/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:41:08 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/22 21:04:50 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_r(t_player *player, float tmp_dirx, float tmp_scrdx)
{
	player->dx = player->dx * cos((M_PI / 180) * VELO_ROT) - player->dy
		* sin((M_PI / 180) * VELO_ROT);
	player->dy = tmp_dirx * sin((M_PI / 180) * VELO_ROT) + player->dy
		* cos((M_PI / 180) * VELO_ROT);
	player->scr_dx = player->scr_dx * cos((M_PI / 180) * VELO_ROT)
		- player->scr_dy * sin((M_PI / 180) * VELO_ROT);
	player->scr_dy = tmp_scrdx * sin((M_PI / 180) * VELO_ROT) + player->scr_dy
		* cos((M_PI / 180) * VELO_ROT);
}

void	rotate_l(t_player *player, float tmp_dirx, float tmp_scrdx)
{
	player->dx = player->dx * cos((M_PI / 180) * VELO_ROT * -1) - player->dy
		* sin((M_PI / 180) * VELO_ROT * -1);
	player->dy = tmp_dirx * sin((M_PI / 180) * VELO_ROT * -1) + player->dy
		* cos((M_PI / 180) * VELO_ROT * -1);
	player->scr_dx = player->scr_dx * cos((M_PI / 180) * VELO_ROT * -1)
		- player->scr_dy * sin((M_PI / 180) * VELO_ROT * -1);
	player->scr_dy = tmp_scrdx * sin((M_PI / 180) * VELO_ROT * -1)
		+ player->scr_dy * cos((M_PI / 180) * VELO_ROT * -1);
}

t_bool	check_wall(t_game *game, int keycode)
{
	int			projected_posx;
	int			projected_posy;
	t_player	*player;

	player = game->player;
	if (keycode == XK_w)
		projected_posx = (int)(player->pos_x + player->dx * VELO_MOV);
	if (keycode == XK_s)
		projected_posx = (int)(player->pos_x - player->dx * VELO_MOV);
	if (keycode == XK_d)
		projected_posx = (int)(player->pos_x - player->dy * VELO_MOV);
	if (keycode == XK_a)
		projected_posx = (int)(player->pos_x + player->dy * VELO_MOV);
	if (keycode == XK_w)
		projected_posy = (int)(player->pos_y + player->dy * VELO_MOV);
	if (keycode == XK_s)
		projected_posy = (int)(player->pos_y - player->dy * VELO_MOV);
	if (keycode == XK_d)
		projected_posy = (int)(player->pos_y + player->dx * VELO_MOV);
	if (keycode == XK_a)
		projected_posy = (int)(player->pos_y - player->dx * VELO_MOV);
	if (game->map->matrix[projected_posy][projected_posx] == '1')
		return (TRUE);
	return (FALSE);
}
