/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:57:47 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/12 21:09:45 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_struct	structure;

	if (argc != 5)
	{
		write(2, "Error - please provide four arguments to the program\n", 53);
		exit(1);
	}
	pipex(&structure, argv, env);
	return (0);
}
