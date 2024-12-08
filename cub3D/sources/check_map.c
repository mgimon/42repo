/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:31:21 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/08 21:35:57 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_end_closed(char *line)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (line[j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	is_line_closed(char *line)
{
	int	j;

	j = 0;
	if (line[j] != '1')
		return (0);
	while (line[j] != '\0')
		j++;
	j--;
	if (line[j] != '1')
		return (0);
	return (1);
}

int	is_it_closed(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix || !matrix[i])
		return (0);
	if (!is_end_closed(matrix[i]))
		return (0);
	i++;
	while (matrix[i])
	{
		if (matrix[i + 1])
		{
			if (!is_line_closed(matrix[i]))
				return (0);
		}
		else
		{
			if (!is_end_closed(matrix[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_it_even(char **matrix)
{
	char	**tmp;
	int		i;
	int		j;
	int		even;

	tmp = matrix;
	i = 0;
	j = 0;
	while (tmp[i][j])
		j++;
	even = j;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
			j++;
		if (j != even)
			return (0);
		i++;
	}
	return (1);
}

int	is_there_room(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_player_existence(char **matrix)
{
	int			i;
	int			j;
	int			count;
	char		*linea;
    const char	caracteres[] = "NSWE";

	i = 0;
	count = 0;
	if (!matrix)
	{
		write(2, "There is no player!\n\n", 21);
		return (1);
	}
    while (matrix[i])
	{
        linea = matrix[i];
        if (linea != NULL)
		{
			j = 0;
            while (linea[j] != '\0')
			{
                if (strchr(caracteres, linea[j]) != NULL)
                    count++;
				j++;
            }
        }
		i++;
    }
	if (!count || count > 1)
	{
		write(2, "There must be one player!\n\n", 27);
		return (1);
	}
	return (0);
}

int	check_valid_map(t_minimap *minimap)
{
	int	even;
	int	closed;
	int	room;

	even = is_it_even(minimap->map);
	if (even != 0)
	{
		closed = is_it_closed(minimap->map);
		if (closed != 0)
		{
			room = is_there_room(minimap->map);
			if (room != 0)
			{
				if (check_player_existence(minimap->map))
					return (0);
				write(2, "The map is correct\n\n", 20);
				return (1);
			}
			write(2, "There is no room\n\n", 18);
			return (0);
		}
		write(2, "The map is even but not closed\n\n", 32);
	}
	else
		write(2, "The map is not even\n\n", 21);
	return (0);
}
