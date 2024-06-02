/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:36:27 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/28 20:07:52 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg)
	{
		while (arg[i] != '\0')
		{
			write(1, &arg[i], 1);
			i++;
		}
	}
}

void	print_args(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j] != '\0')
		{
			write(1, &arg[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
