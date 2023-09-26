/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:39:25 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/27 00:17:42 by nicolasbern      ###   ########.fr       */
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
			if (!(x < 0 || y < 0 || x >= 1920 || y >= 1080))
				((int *)data->img.addr)[(x + i) * (data->img.line_length >> 2) + (y + j)] = color;
				//my_mlx_pixel_put(&data->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

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
				draw_square(data, x * MAP_ZOOM, y * MAP_ZOOM, 0x00FF00300);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	parse_map(argc, argv, &data);
	data.mlx = mlx_init();
	data.mlx_window = mlx_new_window(data.mlx, 1512, 840, "cub3d");
	data.img.img = mlx_new_image(data.mlx, 1920, 1080);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_print_map(&data);
	mlx_loop(data.mlx);
	return (0);
}
