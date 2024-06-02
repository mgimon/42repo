/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:36:57 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/28 22:34:09 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len, int *info);
int		ft_strlen_gnl(const char *str);
char	*ft_strchr_gnl(const char *s, int i);
char	*ft_strdup_gnl(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
