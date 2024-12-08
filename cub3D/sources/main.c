/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:43:56 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/08 20:59:34 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_minimap	*minimap;

	(void)argc;
	(void)argv;
	minimap = NULL;
	minimap = read_map_from_file("maps/test_map.cub");
	if (minimap)
	{
		if (check_valid_map(minimap) != 0)
			write(2, "OK\n\n", 4);
		print_argv(minimap->map);
		free(minimap->map);
		free(minimap);
	}
	return (0);
}
