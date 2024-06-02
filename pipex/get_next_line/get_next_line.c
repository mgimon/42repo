/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:01:10 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/28 22:35:08 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cut_line(char *line, int *info)
{
	char	*nw_line;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	nw_line = ft_substr_gnl(line, 0, i, info);
	if (nw_line == NULL)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (nw_line);
}

static void	free_update_pointer(char **static_str, char *buffer)
{
	char	*temp_str;

	temp_str = *static_str;
	*static_str = ft_strjoin_gnl(temp_str, buffer);
	free(temp_str);
}

static char	*reader(int fd, char *buffer, char *static_str)
{
	int		i;

	i = 1;
	while (i != '\0')
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(static_str), static_str = NULL, NULL);
		else if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!static_str)
		{
			static_str = ft_strdup_gnl("");
			if (!static_str)
				return (NULL);
		}
		free_update_pointer(&static_str, buffer);
		if (!static_str)
			return (NULL);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (static_str);
}

static char	*static_trimmer(char *line, int *info)
{
	size_t	i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	result = ft_substr_gnl(line, i + 1, ft_strlen_gnl(line) - i, info);
	if (!result)
	{
		free(line);
		return (NULL);
	}
	if (*result == '\0')
	{
		free(result);
		result = NULL;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*static_str;
	int			info;

	info = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (static_str = NULL, NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(static_str), static_str = NULL, NULL);
	line = reader(fd, buffer, static_str);
	free(buffer);
	if (!line)
		return (static_str = NULL, NULL);
	static_str = static_trimmer(line, &info);
	if (!static_str && info == 0)
		return (NULL);
	line = cut_line(line, &info);
	if (!line)
		return (free(line), free(static_str), static_str = NULL, NULL);
	return (line);
}
/*
int main(void)
{
	int		fd;
	char	*linea;

	fd = open("multiple_nl.txt", O_RDONLY);
	linea = get_next_line(fd);
	printf("%s", linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	linea = get_next_line(fd);
	printf("%s", linea);
	close(fd);
	return (0);
}*/
