/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon <mgimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:11:12 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/03/06 02:39:16 by mgimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define SCREEN_WITH 1000
# define SCREEN_HIGH 750
# define VELO_MOV 0.05
# define VELO_ROT 3
# define GRIDSIZE 100
# define PLAYERSIZE 4
# define RED 16711680
# define GREEN 65280
# define BLUE 255
# define LIGHT_BLUE 13434879
# define GREY 13158600
# define RADIAN 0.01745329252
# define LINE_SIZE 10
// Texture size must match texture
# define TEXTURE_SIZE 64

typedef enum s_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct s_ray
{
	float		delta_dis_x;
	float		delta_dis_y;
	float		side_dis_x;
	float		side_dis_y;
	int			map_pos[2];
	float		camera_pos[2];
	float		ray_dir[2];
	int			side;
	int			stepx;
	int			stepy;
	float		distance;
	float		camara_dx;
	int			texture_pixel;
}				t_ray;

typedef struct s_texture
{
	int			**texture_no;
	int			**texture_so;
	int			**texture_we;
	int			**texture_ea;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			size;
}				t_texture;

typedef struct s_imgdata
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_imgdata;

typedef struct s_map
{
	char		**map;
	int			fd;
	char		**cub;
	char		**matrix;
	int			sizex;
	int			sizey;
	int			ceiling;
	int			floor;
	t_texture	*textures;
	t_imgdata	*no_texture;
	t_imgdata	*so_texture;
	t_imgdata	*we_texture;
	t_imgdata	*ea_texture;
}				t_map;

typedef struct s_player
{
	char		direction;
	float		pos_x;
	float		pos_y;
	float		dx;
	float		dy;
	float		scr_dx;
	float		scr_dy;
}				t_player;

typedef struct s_game
{
	void		*mlx_connection;
	void		*mlx_window;
	t_map		*map;
	t_player	*player;
	t_imgdata	*img;
	t_ray		*ray;
}				t_game;

// test minilibx
void			img_pixel_put(t_imgdata *img, int x, int y, int color);
void			screen(t_game *game, int color, int size, int offset);
void			clean_close(t_game *game);
int				handle_key(int keycode, t_game *game);
int				handle_close(t_game *game);

// main.c
int				parsing(int argc, char **argv, t_game *game);
void			inits(t_game *game);

// get_map.c
char			*read_line(int fd);
void			init_map_textures(t_game *game);
int				store_map_line(t_game *game, char **result, int *k, char *line);
int				process_map_lines(t_game *game, char **result);
int				get_map(t_game *game, char *filename);

// get_map_2.c
int				cub_size(int fd);
int				is_map_line(char *line);
int				count_map_lines(int fd);
int				ends_with_cub(const char *filename);
int				get_mapsize(char *filename);

// check_map.c
int				is_it_closed(char **matrix, int full_height);
int				does_player_exist(t_game *game, char **matrix);
int				is_player_free(char **matrix);
int				is_player_inside(char **matrix);
int				check_map(t_game *game, char **matrix);

// check_map_utils.c
int				even_map(char **matrix);
int				validate_holes(char **matrix);
int				validate_chars(char **matrix);
int				is_line_empty(char *line);
int				map_full_to_bottom(char **matrix);

// check_map_utils_2.c
int				is_map_last(char **cub);
int				get_full_height(char **matrix);
int				check_line_ends(char *str);
int				get_num_rows(char **matrix);

// events.c
int				handle_key(int keycode, t_game *game);
int				handle_close(t_game *game);

// events_utils.c
void			rotate_r(t_player *player, float tmp_dirx, float tmp_scrdx);
void			rotate_l(t_player *player, float tmp_dirx, float tmp_scrdx);
t_bool			check_wall(t_game *game, int keycode);

// render_fn.c
void			img_pixel_put(t_imgdata *img, int x, int y, int color);
void			paint_window(t_game *game, int color);
void			render_frame(t_game *game);
void			draw_walls(t_game *game, int column, t_ray *ray);

// render_utils.c
void			paint_sky(t_game *game, int start_y, int column);
void			paint_floor(t_game *game, int start_y, int column);

// dda_algorithm.c
void			run_dda_al(t_ray *ray, char **map);
void			draw_rays(t_game *game);
int				**select_tetxture(t_game *game, t_ray *ray);

// dda_algorithm_2.c
void			texture_x_coord(t_ray *ray);
int				is_wall(char **mapa, int x, int y);

// math_fn.c
void			init_player_dir(t_game *game, char dir);

// resources.c
void			get_cub(t_game *game, char *filename);
int				get_hex_from_cubline(char *line);
void			init_resources(t_game *game, char *filename);

// resources_utils.c
void			set_player_pos(t_game *game);
char			*extract_texture_path(char *line, char *prefix);
void			assign_texture(t_game *game, char *prefix, void *img_ptr);
void			load_texture(t_game *game, char *prefix, char *texture_path);
void			get_texture(char *prefix, t_game *game);

// resources_utils_2.c
int				read_buffer(int fd, char *buffer, int *buffer_read,
					int *buffer_pos);
char			*process_buffer(char *buffer, int *buffer_pos, char *line,
					int *i);
char			*get_next_line(int fd);
void			expand_cub(t_game *game, size_t *capacity);
void			read_cub_file(t_game *game, size_t *count, size_t *capacity);

// resources_utils_3.c
int				parse_color_component(char *line, int *i);
int				validate_color_line(char *line, int i);
void			iterate_line(char *line, int *i);
int				get_full_width(char **matrix);
void			parse_colors(t_game *game, char *line);

// texture_fn.c
int				**create_txt_array(int size);
t_bool			init_texture(t_game *game, int size);
void			parse_texture(t_game *game, char *path, char orientation);

// frees.c
void			free_parsing(t_game *game);
void			free_destroy_parsing(t_game *game);
void			clean_close(t_game *game);
void			error_exit(char *msg, int exit_code, t_game *game);
void			free_structs(t_game *game);

// prints.c
void			malloc_err(void);
void			printline_fd(int fd, char *str);
void			printmatrix_fd(int fd, char **str);
void			print_game_data(t_game *game);

#endif
