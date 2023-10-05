/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:39:25 by nibernar          #+#    #+#             */
/*   Updated: 2023/10/03 16:01:05 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	update(t_data *data)
{
	mlx_print_map(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	parse_map(argc, argv, &data);
	data.mlx = mlx_init();
	data.mlx_window = mlx_new_window(data.mlx, MAP_LENGTH, MAP_WIDTH, "cub3d");
	data.img.img = mlx_new_image(data.mlx, MAP_LENGTH, MAP_WIDTH);
	data.img.addr = mlx_get_data_addr(data.img.img, \
	&data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_hook(data.mlx_window, 2, 1L<<0, input, &data);
	mlx_loop_hook(data.mlx, update, &data);
	mlx_loop(data.mlx);
	return (0);
}
