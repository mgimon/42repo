/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:37:55 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/18 19:44:49 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
		fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
		fractal->mlx_window);
	exit(0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		exit(0);
	}
	else if (keycode == ARROW_LEFT)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keycode == ARROW_RIGHT)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keycode == ARROW_UP)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keycode == ARROW_DOWN)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keycode == SHIFT)
		fractal->max_iter += 10;
	else if (keycode == TAB)
		fractal->max_iter -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == SCROLLDOWN)
	{
		fractal->zoom *= 0.8;
	}
	else if (keycode == SCROLLUP)
	{
		fractal->zoom *= 1.2;
	}
	mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
	fractal_render(fractal);
	return (0);
}
