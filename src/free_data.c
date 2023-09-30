/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:33:06 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/29 13:41:30 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_struct_parsing(t_parsing *parsing)
{
	int	i;

	i = 0;
	free(parsing->north_texture);
	free(parsing->south_texture);
	free(parsing->west_texture);
	free(parsing->east_texture);
	free(parsing->floor_color);
	free(parsing->ceiling_color);
	while (parsing->map[i])
		free (parsing->map[i++]);
}
