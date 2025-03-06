/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:59:10 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/23 20:55:40 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	malloc_err(void)
{
	printline_fd(2, "Error: malloc error\n");
	exit(1);
}

void	printline_fd(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void	printmatrix_fd(int fd, char **str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return ;
	while (str[i])
	{
		printline_fd(fd, str[i]);
		write(fd, "\n", 1);
		i++;
	}
}

void	print_game_data(t_game *game)
{
	printmatrix_fd(2, game->map->cub);
	printf("\n");
	printf("Ceiling color: %d\n", game->map->ceiling);
	printf("Floor color: %d\n", game->map->floor);
	printf("Map width: %d\n", game->map->sizex);
	printf("Map height: %d\n", game->map->sizey);
}
