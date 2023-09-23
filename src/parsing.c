/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:49:52 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/23 19:05:32 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_extention(char *str)
{
	str = ft_strrchr(str, '.');
	if (str == NULL)
		return (EXIT_FAILURE);
	if (ft_strncmp(str, ".cub", 4) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static char	*build_map(int fd)
{
	char	*gnl;

	gnl = NULL;
	while (1)
	{
		gnl = ft_get_next_line(fd);
		if (gnl == NULL)
			break ;
		printf("%s", gnl);
		usleep(5000);
		free(gnl);
	}
	return (gnl);
}

t_parsing build_parsing(int fd)
{
	t_parsing	parsing;

	parsing.str = build_map(fd);
	return (parsing);
}

int	parse_map(int argc, char **argv, t_data *data)
{
	int	fd;

	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		printf("wrong nbr of arg !\n");
		return (EXIT_FAILURE);
	}
	if (check_extention(argv[1]))
	{
		printf(".cub needed\n");
		return (EXIT_FAILURE);
	}
	data->parsing = build_parsing(fd);
	//if (check_args_map())
	return (EXIT_SUCCESS);
}