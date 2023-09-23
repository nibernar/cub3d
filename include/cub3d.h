/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:04:15 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/23 18:03:02 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include "../libft/include/libft.h"
# include "../MLX_extention/Lib_MLX/mlx.h"

typedef struct s_parsing
{
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	char	*F;
	char	*C;
	char	*str;
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