/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:39:25 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/30 11:42:08 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
int	end_program(t_data *data)
{
 	mlx_destroy_window(data->mlx, data->mlx_window);
	free_struct_parsing(&data->parsing);
	exit(EXIT_FAILURE);
}

void	moove_to(t_data *data, int flag)
{
	printf("decor avant= %c\n", data->parsing.map[(int)data->player.position.pos_x / MAP_ZOOM][(int)data->player.position.pos_y / MAP_ZOOM]);
	if (data->parsing.map[(int)data->player.position.pos_x / MAP_ZOOM]\
	[(int)data->player.position.pos_y / MAP_ZOOM] == WALL)
	{
		return ;
		// if (flag == 1)
		// {
		// 	data->player.position.pos_x = data->player.position.pos_x + 1;
		// 	return ;
		// }
		// if (flag == 2)
		// {
		// 	data->player.position.pos_x = data->player.position.pos_x - 1;
		// 	return ;
		// }
		// if (flag == 3)
		// {
		// 	data->player.position.pos_y = data->player.position.pos_y + 1;
		// 	printf("decor apres= %c\n", data->parsing.map[(int)data->player.position.pos_x / MAP_ZOOM][(int)data->player.position.pos_y / MAP_ZOOM]);
		// 	return ;
		// }
		// if (flag == 4)
		// {
		// 	data->player.position.pos_y = data->player.position.pos_y - 1;
		// 	return ;
		// }
	}
	//printf("x = %d  y = %d\n", (int)data->player.position.pos_x, (int)data->player.position.pos_y);
	//printf("x = %c  y = %c\n", (int)data->player.position.pos_x, (int)data->player.position.pos_y);
	if (flag == 1)
		data->player.position.pos_x = data->player.position.pos_x - 1;
	if (flag == 2)
		data->player.position.pos_x = data->player.position.pos_x + 1;
	if (flag == 3)
		data->player.position.pos_y = data->player.position.pos_y - 1;
	if (flag == 4)
		data->player.position.pos_y = data->player.position.pos_y + 1;
}

int	input(int key, t_data *data)
{
	if (key == KEY_ESC)
		end_program(data);
	if (key == KEY_UP)
		moove_to(data, 1);
	if (key == KEY_DOWN)
		moove_to(data, 2);
	if (key == KEY_LEFT)
		moove_to(data, 3);
	if (key == KEY_RIGHT)
		moove_to(data, 4);
	return (EXIT_SUCCESS);
}

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
