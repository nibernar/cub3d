/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:39:25 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/29 11:41:01 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
int	end_program(t_data *data)
{
 	mlx_destroy_window(data->mlx, data->mlx_window);
	free_struct_parsing(&data->parsing);
	exit(EXIT_FAILURE);
}

int	input(int key, t_data *data)
{
	dprintf(2, "key = %d\n", key);
	if (key == KEY_ESC)
		end_program(data);
	return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{
	t_data	data;

	parse_map(argc, argv, &data);
	data.mlx = mlx_init();
	data.mlx_window = mlx_new_window(data.mlx, MAP_LENGTH, MAP_WIDTH, "cub3d");
	data.img.img = mlx_new_image(data.mlx, MAP_LENGTH, MAP_WIDTH);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_print_map(&data);
	mlx_hook(data.mlx_window, 2, 1L<<0, input, &data);
	mlx_loop(data.mlx);
	return (0);
}
