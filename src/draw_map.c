/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:44:35 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/30 17:30:19 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_ZOOM)
	{
		j = 0;
		while (j < MAP_ZOOM)
		{
			if (!(x < 0 || y < 0 || x >= MAP_LENGTH || y >= MAP_WIDTH))
				my_mlx_pixel_put(&data->img, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data)
{
		// int	coma_i;
		// int	coma_j;

		// coma_i = (data->player.position.pos_x - floor(data->player.position.pos_x)) * 10;
		// coma_j = (data->player.position.pos_y - floor(data->player.position.pos_y)) * 10;
		my_mlx_pixel_put(&data->img, data->player.position.pos_y, data->player.position.pos_x, 0x0066FF00);
}

// static void	draw_player(t_data *data)
// {
// 	int	coma_i;
// 	int	coma_j;
// 	int	x;
// 	int	y;

// 	coma_i = (data->player.position.pos_x - floor(data->player.position.pos_x)) * 10;
// 	coma_j = (data->player.position.pos_y - floor(data->player.position.pos_y)) * 10;
// 	x = 2;
// 	while (x < MAP_ZOOM - 2)
// 	{
// 		y = 2;
// 		while (y < MAP_ZOOM - 2)
// 		{
// 			if (x + MINI_SIZE * MAP_ZOOM + coma_i >= 0 && y + MINI_SIZE * MAP_ZOOM + coma_j >= 0\
// 			&& x + MINI_SIZE * MAP_ZOOM + coma_i < MAP_LENGTH && y + MINI_SIZE * MAP_ZOOM + coma_j < MAP_WIDTH)
// 				((int *)data->img.addr)[((x + MINI_SIZE * MAP_ZOOM) + coma_i) * \
// 				(data->img.line_length >> 2) + ((y + MINI_SIZE * MAP_ZOOM) + coma_j)] = 0x00003399;
// 			y++;
// 		}
// 		x++;
// 	}
// }

void	mlx_print_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->parsing.map[x])
	{
		y = 0;
		while (data->parsing.map[x][y])
		{
			if (data->parsing.map[x][y] == '1')
				draw_square(data, x * MAP_ZOOM, y * MAP_ZOOM, 0x00FF66FF);
			if (data->parsing.map[x][y] == '0')
				draw_square(data, x * MAP_ZOOM, y * MAP_ZOOM, 0x00000000);
			if (check_dir(data->parsing.map[x][y]))
				draw_square(data, x * MAP_ZOOM, y * MAP_ZOOM, 0x000066FF);
			y++;
		}
		x++;
	}
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img.img, 0, 0);
}