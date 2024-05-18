/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:36:28 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/18 18:32:02 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// MANDELBROT -> z = z^2 + c ->(Z initially is (0,0)
//
//To properly view Julia, params should be around -0.8 for x, and 0.1 for y

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_hook(fractal.mlx_window, 4, 0, mouse_handler, &fractal);
		mlx_key_hook(fractal.mlx_window, key_handler, &fractal);
		mlx_hook(fractal.mlx_window, ON_DESTROY, 0, close_handler, &fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		write(1, "Please enter \n\t\"./fractol mandelbrot\" or ", 41);
		write(1, "\n\t\"./fractol julia <value_1> <value_2>\"\n", 40);
		exit(0);
	}
}
