/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:28:44 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/27 15:36:25 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_extention(char *str)
{
	str = ft_strrchr(str, '.');
	if (str == NULL)
		return (EXIT_FAILURE);
	if (ft_strncmp(str, ".cub", 4) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_double_map(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!ft_isspace(str[i]))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	check_and_trim(char *file, t_parsing *parsing)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (ft_isalpha(file[i]))
		{
			printf("ERROR file\n");
			return (EXIT_FAILURE);
		}
		if (ft_isdigit(file[i]))
		{
			parsing->trimed = 1;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}