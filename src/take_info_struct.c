/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:40:49 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/27 15:41:14 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int		take_path(char *map, t_parsing *parsing, int flag)
{
	if (flag == 1)
		parsing->north_texture = ft_strdup(map);
	if (flag == 2)
		parsing->south_texture = ft_strdup(map);
	if (flag == 3)
		parsing->west_texture = ft_strdup(map);
	if (flag == 4)
		parsing->east_texture = ft_strdup(map);
	if (flag == 5)
		parsing->floor_color = ft_strdup(map);
	if (flag == 6)
		parsing->ceiling_color = ft_strdup(map);
	parsing->nbr_info++;
	return (EXIT_SUCCESS);
}

int	take_information(char *map, t_parsing *parsing)
{
	if (ft_strncmp("NO ./", map, 5) == 0)
		return (take_path(map, parsing, 1));
	else if (ft_strncmp("SO ./", map, 5) == 0)
		return (take_path(map, parsing, 2));
	else if (ft_strncmp("WE ./", map, 5) == 0)
		return (take_path(map, parsing, 3));
	else if (ft_strncmp("EA ./", map, 5) == 0)
		return (take_path(map, parsing, 4));
	else if (ft_strncmp("F ", map, 2) == 0)
		return (take_path(map, parsing, 5));
	else if (ft_strncmp("C ", map, 2) == 0)
		return (take_path(map, parsing, 6));
	if (map[0] != '\0')
	{
		printf("ERROR MAP |%c|\n", map[0]);
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}