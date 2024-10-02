/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:29:58 by mirifern          #+#    #+#             */
/*   Updated: 2024/10/02 10:54:27 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

void	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = ft_strlen(s1);
	str = malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy((str + len), s2);
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*newline;
	int		count;
	int		copy;
	static char	buf[BUFFER_SIZE];

	line = ft_strdup(buf);
	while (!(newline = ft_strchr(line, '\n')) && (count = read (fd, buf, BUFFER_SIZE)))
	{
		buf[count] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	if (newline != NULL)
	{
		copy = newline - line +1;
		ft_strcpy(buf, newline + 1);
	}
	else
	{
		copy = ft_strlen(line);
		buf[0] = '\0';
	}
	line[copy] = '\0';
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDONLY);
	printf("LINE = %s", get_next_line(fd));
	printf("LINE = %s", get_next_line(fd));
	printf("LINE = %s", get_next_line(fd));
	printf("LINE = %s", get_next_line(fd));
	printf("LINE = %s", get_next_line(fd));
	printf("LINE = %s", get_next_line(fd));
	return(0);
}*/
