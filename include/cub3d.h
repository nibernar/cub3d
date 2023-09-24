/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:04:15 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/24 17:36:13 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include "../libft/include/libft.h"
# include "../MLX_extention/Lib_MLX/mlx.h"

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
	t_parsing	parsing;
}	t_data;

/*************
*	Parsing  *
*************/
int	parse_map(int argc, char **argv, t_data *data);
#endif