/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:04:15 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/27 00:18:15 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <math.h>
# include "../libft/include/libft.h"
//macos
# include "../mlx/mlx.h"
//linux
# include "../MLX_extention/Lib_MLX/mlx.h"
# include "../mlx/mlx.h"

# define MAP_ZOOM 15

typedef struct	s_image {
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

int	parse_map(int argc, char **argv, t_data *data);
void	print_struct(t_parsing *parsing);

#endif