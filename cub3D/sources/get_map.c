/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:56:41 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/08 21:00:47 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_map_line(const char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != 'N'
			&& line[i] != 'W' && line[i] != 'E' && line[i] != 'S')
			return (0);
		i++;
	}
	return (1);
}

char	*read_line(int fd)
{
	char	*line;
	int		i;
	int		bytes_read;

	line = malloc(256);
	if (!line)
		return (NULL);
	i = 0;
	while ((bytes_read = read(fd, &line[i], 1)) > 0)
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (bytes_read <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

char	**expand_map(char **map, int old_capacity, int new_capacity)
{
	int	i;
	char **new_map;

	new_map = malloc(sizeof(char *) * new_capacity);
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < old_capacity)
	{
		new_map[i] = map[i];
		i++;
	}
	free(map);
	return (new_map);
}

t_minimap	*read_map_from_file(const char *filename)
{
	int			fd;
	int			i;
	char		*line;
	int			map_capacity;
	t_minimap	*minimap;

	i = 0;
	map_capacity = 10;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error de open\n", 14);
		return (NULL);
	}
	minimap = malloc(sizeof(t_minimap));
	if (!minimap)
	{
		close(fd);
		return (NULL);
	}
	minimap->map = malloc(sizeof(char *) * map_capacity);
	if (!minimap->map)
	{
		free(minimap);
		close(fd);
		return (NULL);
	}
	while ((line = read_line(fd)) != NULL)
	{
		if (is_map_line(line))
		{
			if (i >= map_capacity)
			{
				map_capacity *= 2;
				minimap->map = expand_map(minimap->map, i, map_capacity);
				if (!minimap->map)
				{
					write(2, "Error de memoria\n", 17);
					close(fd);
					free(line);
					free(minimap);
					return (NULL);
				}
			}
			minimap->map[i++] = line;
		}
		else
			free(line);
	}
	minimap->map[i] = NULL;
	close(fd);
	return (minimap);
}
