/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:57:47 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/08 15:05:03 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_struct	structure;

	if (argc != 5)
	{
			ft_printf("Error - please provide four arguments to the program\n");
			exit(1);
	}
	pipex(&structure, argv, env);
	return (0);
}
