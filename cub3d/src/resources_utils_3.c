/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:57:04 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/22 21:57:04 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parse_color_component(char *line, int *i)
{
	int	color;

	color = 0;
	while (ft_isdigit(line[*i]))
	{
		color = color * 10 + (line[*i] - '0');
		(*i)++;
	}
	if (color < 0 || color > 255)
		return (-1);
	return (color);
}

int	validate_color_line(char *line, int i)
{
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		|| line[i] == '\r')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}

void	iterate_line(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
}

int	get_full_width(char **matrix)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
			j++;
		if (j > width)
			width = j;
		i++;
	}
	return (width);
}

void	parse_colors(t_game *game, char *line)
{
	int	color;

	color = get_hex_from_cubline(line);
	if (color == -1)
	{
		printf("\nError parsing color on line: %s\n", line);
		exit(1);
	}
	if (line[0] == 'C')
		game->map->ceiling = color;
	else
		game->map->floor = color;
}
