/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:00:53 by nibernar          #+#    #+#             */
/*   Updated: 2023/10/10 13:58:01 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	end_program(t_data *data)
{
 	//mlx_destroy_window(data->mlx, data->mlx_window);
	//free_struct_parsing(&data->parsing);
	exit(EXIT_FAILURE);
}

void	move_up(t_data *data)
{
	data->player.position.pos_x += data->player.direction.pos_x * MOVE_SPEED;
	data->player.position.pos_y += data->player.direction.pos_y * MOVE_SPEED;
}

void	move_down(t_data *data)
{
	data->player.position.pos_x -= data->player.direction.pos_x * MOVE_SPEED;
	data->player.position.pos_y -= data->player.direction.pos_y * MOVE_SPEED;
}

void	move_right(t_data *data)
{
  	double old_dir_x;

	data->player.angle_player += ROT_SPEED;
		if (data->player.angle_player > 2 * M_PI)
		data->player.angle_player = 0;
	old_dir_x = data->player.direction.pos_x;
  	data->player.direction.pos_x = data->player.direction.pos_x * cos(ROT_SPEED) - data->player.direction.pos_y * sin(ROT_SPEED);
  	data->player.direction.pos_y = old_dir_x * sin(ROT_SPEED) + data->player.direction.pos_y * cos(ROT_SPEED);
}

void	move_left(t_data *data)
{
  	double old_dir_x;

	data->player.angle_player -= ROT_SPEED;
	if (data->player.angle_player < -2 * M_PI)
		data->player.angle_player = 0;
	old_dir_x = data->player.direction.pos_x;
  	data->player.direction.pos_x = data->player.direction.pos_x * cos(-ROT_SPEED) - data->player.direction.pos_y * sin(-ROT_SPEED);
  	data->player.direction.pos_y = old_dir_x * sin(-ROT_SPEED) + data->player.direction.pos_y * cos(-ROT_SPEED);
}

int	input(int key, t_data *data)
{
	if (key == KEY_ESC)
		end_program(data);
	if (key == KEY_UP)
		move_up(data);
	if (key == KEY_DOWN)
		move_down(data);
	if (key == KEY_LEFT)
		move_left(data);
	if (key == KEY_RIGHT)
		move_right(data);
	// if (key == KEY_POV_RIGHT)
	// 	moove_rot_to(data, 1);
	// if (key == KEY_POV_LEFT)
	// 	moove_rot_to(data, 2);
	return (EXIT_SUCCESS);
}
