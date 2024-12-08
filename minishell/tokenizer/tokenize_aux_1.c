/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_aux_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:19:22 by albealva          #+#    #+#             */
/*   Updated: 2024/11/11 12:51:24 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_copy;

	dest_copy = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_copy);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	get_old_size(char *ptr)
{
	size_t	size;

	size = 0;
	if (ptr == NULL)
		return (0);
	while (ptr[size] != '\0')
		size++;
	return (size);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*trolft_strdup(const char *s1, t_general *info)
{
	char	*s1_copy;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	s1_copy = my_malloc(info, i + 1);
	if (s1_copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s1_copy[i] = (char)s1[i];
		i++;
	}
	s1_copy[i] = '\0';
	return ((char *)s1_copy);
}
