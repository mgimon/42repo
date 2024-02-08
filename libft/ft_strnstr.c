/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:54:21 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/17 22:44:34 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenneedle;

	i = 0;
	lenneedle = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len)
	{
		while (haystack[i] != '\0')
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				if (j == lenneedle - 1)
					return ((char *)&haystack[i]);
				j++;
			}
			i++;
		}
		return (NULL);
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	haystack[] = "gaztelugatxe";
	const char	needle[] = "gat";
	size_t		len = 11;

	printf("The result is: %s \n", strnstr(haystack, needle, len));
	printf("My result is: %s \n", ft_strnstr(haystack, needle, len));
	return (0);
}
*/
