/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:44:35 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/27 15:44:47 by nibernar         ###   ########.fr       */
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