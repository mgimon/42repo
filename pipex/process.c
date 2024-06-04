/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:18:23 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/04 22:53:47 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_struct structure)
{

}

void	child_process(t_struct structure)
{

}

void	pipex(t_struct structure)
{
	pid_t	process;
	int	sides[2];

	pipe(sides);
	process = fork();
	if (process < 0)
		//Hacer frees, perror y exit
	if (process == 0)
		child_process(structure); //ejecutar el cmd1
	else
		parent_process(structure); //ejecutar el cmd2 con la salida del cmd1
}
