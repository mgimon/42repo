/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:54:55 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/22 20:56:12 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_map_last(char **cub)
{
	int	i;
	int	map_line;

	i = 0;
	map_line = 0;
	while (cub[i])
	{
		if (is_map_line(cub[i]))
			map_line++;
		else
		{
			if (map_line != 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	get_full_height(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	check_line_ends(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] == ' ')
		i++;
	if (str[i] != '1')
		return (1);
	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] == ' ')
		i--;
	if (str[i] != '1')
		return (1);
	return (0);
}

int	get_num_rows(char **matrix)
{
	int	rows;

	rows = 0;
	while (matrix[rows] != NULL)
		rows++;
	return (rows);
}
