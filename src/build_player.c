/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:43:28 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/10/05 11:08:00 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//créer struct player
//trouver l'emplacement de la case player avec flot
//trouver le pixel au milieu de la case player
//tracer une droite devant lui
//faire en sorte que la droite s'arret quand elle percute un mur
//tracer un rayon de droite de 60°
//faire en sorte que les droite du rayon s'arretent quand elles percutent un mur

int check_dir(char c)
{
    return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

void    set_dir(t_data *data)
{
    if (data->player.dir == 'N')
    {
        data->player.angle_player = M_PI_2;
        data->player.direction.pos_x = 0;
        data->player.direction.pos_y = 1;
    }
    if (data->player.dir == 'S')
    {
        data->player.angle_player = - M_PI_2;
        data->player.direction.pos_x = 0;
        data->player.direction.pos_y = -1;
    }
    if (data->player.dir == 'E')
    {
        data->player.angle_player = 2 * M_PI;
        data->player.direction.pos_x = 1;
        data->player.direction.pos_y = 0;
    }
    if (data->player.dir == 'W')
    {
        data->player.angle_player = M_PI;
        data->player.direction.pos_x = -1;
        data->player.direction.pos_y = 0;
    }
}

void   player_pos(t_data *data)
{
    int y;
    int x;
    float   tmp_x;
    float   tmp_y;

    y = 0;
    tmp_x = 0;
    tmp_y = 0;
    while(data->parsing.map[y])
    {
        x = 0;
        while (data->parsing.map[y][x])
        {
            if (check_dir(data->parsing.map[y][x]))
            {
                data->player.dir = data->parsing.map[y][x];
                data->parsing.map[y][x] = '0';
                tmp_x = (float) x;
                tmp_y = (float) y;
                data->player.position.pos_x = tmp_x * MAP_ZOOM + MAP_ZOOM * 0.5;
                data->player.position.pos_y = tmp_y * MAP_ZOOM + MAP_ZOOM * 0.5;
                set_dir(data);
                //dprintf(2, "y = %d  x = %d\n", y, x);
                //dprintf(2, "y + 1 = %d  x + 1 = %d\n", y + (int)data->player.direction.pos_y, x + (int)data->player.direction.pos_x);
            }
           x++;
        }
        y++;
    }
}

int build_player(t_data *data)
{
    player_pos(data);
    return (0);
}