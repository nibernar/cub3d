/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:43:28 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/29 15:29:11 by nicolasbern      ###   ########.fr       */
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

void   player_pos(t_data *data)
{
    int i;
    int j;
    float   tmp_x;
    float   tmp_y;

    i = 0;
    tmp_x = 0;
    tmp_y = 0;
    while(data->parsing.map[i])
    {
        j = 0;
        while (data->parsing.map[i][j])
        {
            if (check_dir(data->parsing.map[i][j]))
            {
                data->player.dir = data->parsing.map[i][j];
                tmp_x = (float) i;
                tmp_y = (float) j;
                data->player.position.pos_x = tmp_x * MAP_ZOOM + MAP_ZOOM * 0.5;
                data->player.position.pos_y = tmp_y * MAP_ZOOM + MAP_ZOOM * 0.5;
            }
           j++;
        }
        i++;
    }
}

int build_player(t_data *data)
{
    player_pos(data);
    return (0);
}