/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:04:15 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/28 11:30:03 by nicolasbern      ###   ########.fr       */
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

# define MAP_ZOOM 20
# define MAP_LENGTH 1080
# define MAP_WIDTH 850


typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

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

typedef struct s_data
{
	void		*mlx;
	void		*mlx_window;
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

#endif