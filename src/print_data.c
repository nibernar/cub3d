/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:34:24 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/27 15:35:56 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_struct(t_parsing *parsing)
{
	int	i;
	printf("%s\n", parsing->north_texture);
	printf("%s\n", parsing->south_texture);
	printf("%s\n", parsing->west_texture);
	printf("%s\n", parsing->east_texture);
	printf("%s\n", parsing->floor_color);
	printf("%s\n", parsing->ceiling_color);
	if (parsing->map)
	{
		i = 0;
		while (parsing->map[i])
			printf("%s\n", parsing->map[i++]);
	}
}
