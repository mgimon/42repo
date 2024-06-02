/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:57:47 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/06/02 18:54:20 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex	vehicles.txt "grep powerboat" "wc -w" empty.txt
// 			<vehicles.txt grep powerboat | wc -w >empty.txt
// 	if (execve("/bin/grep", cmd1, str, fd1, NULL) == -1)
// 	{
//		perror("execve");
//		return (1);
//  }
int	main(int argc, char **argv, char **env)
{
	t_struct	structure;

	if (argc != 5)
	{
			ft_printf("Error - please provide four arguments to the program\n");
			exit(1);
	}
	struct_init(&structure, argv, env);
	printf("\nEl path_cmd1 es %s\n", structure.path_cmd1);
	printf("\nEl path_cmd2 es %s\n", structure.path_cmd2);

	///-----------LIBERACION-----------///
	free(structure.cmd1);
	free(structure.cmd2);
	free(structure.path_cmd1);
	free(structure.path_cmd2);
	matrix_free(structure.path);
	///-----------END-LIBERACION-------///

	return (0);
}
