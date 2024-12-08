/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:45:16 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/08 21:00:02 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_minimap
{
	char	**map;
}			t_minimap;

// prints.c
void		print_argv(char **argv);

// frees.c
void		free_argv(char **argv);

// get_map.c
t_minimap	*read_map_from_file(const char *filename);

// check_map.c
int			check_valid_map(t_minimap *minimap);

#endif
