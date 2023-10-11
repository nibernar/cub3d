/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:04:15 by nibernar          #+#    #+#             */
/*   Updated: 2023/10/10 23:58:45 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/include/libft.h"
//# include "../mlx_linux/mlx.h"
# include "../mlx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

# define MAP_ZOOM 16
# define MAP_LENGTH 1080
# define MAP_WIDTH 850
# define MOVE_SPEED 7
# define ROT_SPEED 0.3
# define MINI_SIZE 10
# define FOV 45

//linux
// typedef enum e_key
// {
// 	KEY_UP = 119,
// 	KEY_DOWN = 115, 
// 	KEY_RIGHT = 100, 
// 	KEY_LEFT = 97,
// 	KEY_ESC = 65307,
// 	KEY_POV_RIGHT = 65363,
// 	KEY_POV_LEFT = 65361,
// }	t_key;

//macos
typedef enum e_key
{
	KEY_UP = 13,
	KEY_DOWN = 1, 
	KEY_RIGHT = 2, 
	KEY_LEFT = 0,
	KEY_ESC = 53,
	KEY_POV_RIGHT = 65363,
	KEY_POV_LEFT = 65361,
}	t_key;

typedef enum e_decor
{
	WALL = '1',
	EMPTY = '2',
}	t_decor;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_pos
{
	float	pos_x;
	float	pos_y;
}	t_pos;

typedef struct s_parsing
{
	int		nbr_info;
	int		trimed;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*ceiling_color;
	char	**file;
	char	**map;
}	t_parsing;

typedef struct s_player
{
	t_pos	position;
	t_pos	direction;
	float	angle_player;
	double	angle_fov;
	char	dir;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_window;
	t_player	player;
	t_image		img;
	t_parsing	parsing;
}	t_data;

/*************
*	Parsing  *
*************/

int		take_path(char *map, t_parsing *parsing, int flag);
int		take_information(char *map, t_parsing *parsing);
int		parse_map(int argc, char **argv, t_data *data);
int		check_extention(char *str);
int		check_double_map(char *str);
int		check_and_trim(char *file, t_parsing *parsing);
int 	build_player(t_data *data);

/*****************
*	Draw_map     *
*****************/

void	mlx_print_map(t_data *data);
void	draw_square(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

/*************
*	Free     *
*************/

void	free_struct_parsing(t_parsing *parsing);

/*****************
*	Print_data   *
*****************/

void	print_struct(t_parsing *parsing);

int 	check_dir(char c);
int		input(int key, t_data *data);
void	moove_to(t_data *data, int flag);
int		end_program(t_data *data);

#endif