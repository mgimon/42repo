/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:59:10 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/10 17:32:11 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	printline_fd(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void	printmatrix_fd(int fd, char **str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return ;
	while (str[i])
	{
		printline_fd(fd, str[i]);
		write(fd, "\n", 1);
		i++;
	}
}
