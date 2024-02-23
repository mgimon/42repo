/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:36 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/01/19 19:24:59 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;
	size_t	i;

	total_size = count * size;
	ptr = malloc(total_size);
	i = 0;
	if (ptr != NULL)
	{
		while (i < total_size)
		{
			((char *)ptr)[i] = 0;
			i++;
		}
	}
	return (ptr);
}
/*
int	main(void)
{
	return (0);
}
*/
