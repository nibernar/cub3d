/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:44:35 by nibernar          #+#    #+#             */
/*   Updated: 2023/10/11 16:00:38 by nicolasbern      ###   ########.fr       */
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

static int	hit_wall(t_data *data, int i, int j)
{
	int	x;

	x = 0;
	while (data->parsing.map[x])
		x++;
	x *= MAP_ZOOM;
	if (i < 0 || j < 0 || i > MAP_WIDTH || j > MAP_LENGTH)
		return (0);
	if (i < x && data->parsing.map[(int)floor(i) / MAP_ZOOM][(int)floor(j) / MAP_ZOOM] && (int)floor(j) / MAP_ZOOM < ft_strlen(data->parsing.map[(int)floor(i) / MAP_ZOOM]))
		if (data->parsing.map[(int)floor(i) / MAP_ZOOM][(int)floor(j) / MAP_ZOOM] == '1')
			return (0);
	return (1);
}

void	draw_player(t_data *data, float angle_fov)
{
	float 	new_x = 0;
	float 	new_y = 0;
	float	step = 1;
	float	dx = cos(data->player.angle_player + angle_fov);
	float	dy = sin(data->player.angle_player + angle_fov);
	double	j;
	double	i;

	i = data->player.position.pos_x;
	j = data->player.position.pos_y;
	while (hit_wall(data, j, i))
	{
		new_x += step * dx;
		new_y += step * dy;
		my_mlx_pixel_put(&data->img, data->player.position.pos_x + new_x, data->player.position.pos_y + new_y, 0x00FFFF00);
		i += dx;
		j += dy;
	}
}

void	mlx_print_map(t_data *data)
{
	float angle_fov;
	int	x;
	int	y;

	y = 0;
	angle_fov = (FOV * (M_PI / 180) / 2);
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
	draw_player(data, 0);
	draw_player(data, angle_fov);
	draw_player(data, -angle_fov);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img.img, 0, 0);
}
