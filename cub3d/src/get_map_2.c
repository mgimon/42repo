/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:29:46 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/22 21:34:00 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	cub_size(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = read_line(fd);
	while (line != NULL)
	{
		i++;
		line = read_line(fd);
	}
	return (i);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

int	count_map_lines(int fd)
{
	int		n;
	char	*line;

	n = 0;
	line = read_line(fd);
	while (line != NULL)
	{
		if (is_map_line(line))
			n++;
		free(line);
		line = read_line(fd);
	}
	return (n);
}

int	ends_with_cub(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}

int	get_mapsize(char *filename)
{
	int	fd;
	int	map_size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	map_size = count_map_lines(fd);
	close(fd);
	return (map_size);
}
