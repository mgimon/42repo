/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:57:04 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/22 21:57:04 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	read_buffer(int fd, char *buffer, int *buffer_read, int *buffer_pos)
{
	*buffer_read = read(fd, buffer, 1024);
	*buffer_pos = 0;
	return (*buffer_read);
}

char	*process_buffer(char *buffer, int *buffer_pos, char *line, int *i)
{
	if (buffer[*buffer_pos] == '\n')
	{
		line[(*i)++] = buffer[(*buffer_pos)++];
		return (line);
	}
	line[(*i)++] = buffer[(*buffer_pos)++];
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024];
	static int	buffer_read = 0;
	static int	buffer_pos = 0;
	char		*line;
	int			i;

	line = malloc(70000);
	if (fd < 0 || !line)
		return (NULL);
	i = 0;
	while (1)
	{
		if (buffer_pos >= buffer_read
			&& read_buffer(fd, buffer, &buffer_read, &buffer_pos) <= 0)
			break ;
		if (process_buffer(buffer, &buffer_pos, line, &i))
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (free(line), NULL);
	return (line);
}

void	expand_cub(t_game *game, size_t *capacity)
{
	char	**new_cub;

	*capacity *= 2;
	new_cub = realloc(game->map->cub, sizeof(char *) * (*capacity));
	if (!new_cub)
		malloc_err();
	game->map->cub = new_cub;
}

void	read_cub_file(t_game *game, size_t *count, size_t *capacity)
{
	char	*line;

	line = get_next_line(game->map->fd);
	while (line)
	{
		if (*count >= *capacity - 1)
			expand_cub(game, capacity);
		game->map->cub[(*count)++] = line;
		line = get_next_line(game->map->fd);
	}
}
