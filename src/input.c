/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:00:53 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/30 17:35:34 by nibernar         ###   ########.fr       */
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
	// if (data->parsing.map[(int)data->player.position.pos_x / MAP_ZOOM]\
	// [(int)data->player.position.pos_y / MAP_ZOOM] == WALL)
	// 	return ;
	if (flag == 1)
		data->player.position.pos_x = data->player.position.pos_x - 1 * MOOV_SPEED;
	if (flag == 2)
		data->player.position.pos_x = data->player.position.pos_x + 1 * MOOV_SPEED;
	if (flag == 3)
		data->player.position.pos_y = data->player.position.pos_y - 1 * MOOV_SPEED;
	if (flag == 4)
		data->player.position.pos_y = data->player.position.pos_y + 1 * MOOV_SPEED;
}

void	moove_rot_to(t_data *data, int flag)
{
	if (flag == 1)
	{
		printf("zgeg\n");
		data->player.position.pos_x = data->player.position.pos_x * cos(- ROT_SPEED) - data->player.position.pos_y * sin(- ROT_SPEED);
		data->player.position.pos_y = data->player.position.pos_y * cos(- ROT_SPEED) + data->player.position.pos_x * sin(- ROT_SPEED);
		// data->player.position.pos_x = (int)(data->player.position.pos_x * cos(Phi * (PI / 180)) - data->player.position.pos_y * sin(Phi * (PI / 180)));
		// data->player.position.pos_y = (int)(data->player.position.pos_x * cos(Phi * (PI / 180)) + data->player.position.pos_y * sin(Phi * (PI / 180)));
	}

	if (flag == 2)
	{
		printf("zgeg2\n");
		data->player.position.pos_x = data->player.position.pos_x * cos(ROT_SPEED) - data->player.position.pos_y * sin(ROT_SPEED);
		data->player.position.pos_y = data->player.position.pos_y * cos(ROT_SPEED) + data->player.position.pos_x * sin(ROT_SPEED);
		// data->player.position.pos_x = (int)(data->player.position.pos_x * cos(Phi * (PI / 180)) + data->player.position.pos_y * sin(Phi * (PI / 180)));
		// data->player.position.pos_y = (int)(data->player.position.pos_x * cos(Phi * (PI / 180)) - data->player.position.pos_y * sin(Phi * (PI / 180)));
	}
}

int	input(int key, t_data *data)
{
	printf("%d\n", key);
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
	if (key == KEY_POV_RIGHT)
		moove_rot_to(data, 1);
	if (key == KEY_POV_LEFT)
		moove_rot_to(data, 2);
	return (EXIT_SUCCESS);
}

// int x1= (int)(x*cos(Phi*(PI/180))-y*sin(Phi*(PI/180)));
// int y1= (int)(x*cos(Phi*(PI/180))+y*sin(Phi*(PI/180)));