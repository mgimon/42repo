/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:28:20 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/22 22:00:18 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	**create_txt_array(int size)
{
	int	i;
	int	**arra_txt;

	i = 0;
	arra_txt = ft_calloc(size, sizeof(int *));
	if (!arra_txt)
		return (NULL);
	while (i < size)
	{
		arra_txt[i] = ft_calloc(size, sizeof(int));
		if (!arra_txt)
			return (NULL);
		i++;
	}
	return (arra_txt);
}

static int	get_color(t_imgdata *img, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	color = *(int *)pixel;
	return (color);
}

t_bool	init_texture(t_game *game, int size)
{
	t_texture	*txt;

	txt = game->map->textures;
	txt->texture_no = create_txt_array(size);
	if (!txt->texture_no)
		return (FALSE);
	txt->texture_so = create_txt_array(size);
	if (!txt->texture_so)
		return (FALSE);
	txt->texture_ea = create_txt_array(size);
	if (!txt->texture_ea)
		return (FALSE);
	txt->texture_we = create_txt_array(size);
	if (!txt->texture_we)
		return (FALSE);
	txt->size = size;
	return (TRUE);
}

static void	xmp_to_int(t_imgdata *img, int **txt, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			txt[i][j] = get_color(img, j, i);
			j++;
		}
		i++;
	}
}

void	parse_texture(t_game *game, char *path, char orientation)
{
	t_imgdata	img;
	t_texture	*txt;

	txt = game->map->textures;
	img.img = mlx_xpm_file_to_image(game->mlx_connection, path, &txt->size,
			&txt->size);
	if (!img.img)
	{
		printline_fd(2, "Error: couldn't get a texture!\n");
		exit(1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (orientation == 'N')
		xmp_to_int(&img, txt->texture_no, txt->size);
	if (orientation == 'S')
		xmp_to_int(&img, txt->texture_so, txt->size);
	if (orientation == 'E')
		xmp_to_int(&img, txt->texture_ea, txt->size);
	if (orientation == 'W')
		xmp_to_int(&img, txt->texture_we, txt->size);
	mlx_destroy_image(game->mlx_connection, img.img);
}
