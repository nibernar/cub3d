/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:44:35 by nibernar          #+#    #+#             */
/*   Updated: 2023/10/05 18:28:00 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int pos_x, int pos_y, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < MAP_ZOOM)
	{
		x = 0;
		while (x < MAP_ZOOM)
		{
			if (!(pos_x < 0 || pos_y < 0 || pos_x >= MAP_LENGTH || pos_y >= MAP_WIDTH))
				my_mlx_pixel_put(&data->img, pos_y + y, pos_x + x, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	my_mlx_pixel_put(&data->img, data->player.position.pos_x, data->player.position.pos_y, 0x0066FF00);
	my_mlx_pixel_put(&data->img, data->player.position.pos_x + data->player.direction.pos_x, data->player.position.pos_y + data->player.direction.pos_y, 0x00FFFF00);
}

void	mlx_print_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->parsing.map[y])
	{
		x = 0;
		while (data->parsing.map[y][x])
		{
			if (data->parsing.map[y][x] == '1')
				draw_square(data, y * MAP_ZOOM, x * MAP_ZOOM, 0x00FF66FF);
			if (data->parsing.map[y][x] == '0')
				draw_square(data, y * MAP_ZOOM, x * MAP_ZOOM, 0x00000000);
			if (check_dir(data->parsing.map[y][x]))
				draw_square(data, y * MAP_ZOOM, x * MAP_ZOOM, 0x000066FF);
			x++;
		}
		y++;
	}
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img.img, 0, 0);
}