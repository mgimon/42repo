/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:52:26 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/10 17:32:19 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int	get_mapsize(char *filename)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	n = 0;
	while ((line = read_line(fd)) != NULL)
	{
		free(line);
		n++;
	}
	close(fd);
	return (n > 8 ? n - 8 : 0);
}

void	get_map(t_tmap *tmap, char *filename)
{
	int			fd;
	int			i;
	int			k;
	char		*line;
	char		**result;
	int			map_size;

	map_size = get_mapsize(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || map_size <= 0)
	{
		printline_fd(2, "Open failed or invalid map size\n");
		return ;
	}
	result = malloc(sizeof(char *) * (map_size + 1));
	i = 0;
	k = 0;
	while ((line = read_line(fd)) != NULL)
	{
		if (i >= 8)
		{
			result[k] = ft_strdup(line);
			free(line);
			if (!result[k++])
			{
				while (--k >= 0)
					free(result[k]);
				free(result);
				close(fd);
				return ;
			}
		}
		else
			free(line);
		i++;
	}
	result[k] = NULL;
	close(fd);
	tmap->matrix = result;
}
