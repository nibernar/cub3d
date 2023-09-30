/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:49:52 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/29 13:44:05 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	**build_file(int fd)
{
	char	*gnl;
	char	*tmp;
	char	*str;
	char	**file;

	gnl = NULL;
	tmp = NULL;
	str = NULL;
	file = NULL;
	while (1)
	{
		gnl = ft_get_next_line(fd);
		if (gnl == NULL)
			break ;
		tmp = ft_strjoin(str, gnl);
		free(gnl);
		free(str);
		str = tmp;
	}
	file = ft_split(str, '\n');
	free(str);
	return (file);
}

static char	**build_map(char **str)
{
	int	i;
	int j;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == '\0')
		{
			printf("ERROR map\n");
			return (NULL);
		}
		j = -1;
		while (str[i][++j])
		{
			if (ft_isspace(str[i][0]))
			{
				if (check_double_map(str[i]))
				{
					printf("ERROR map\n");
					return (NULL);
				}
			}
		}
	}
	return (str);
}

static int build_parsing(int fd, t_data *data)
{
	char		*str;
	int			i;

	i = 0;
	str = NULL;
	data->parsing.nbr_info = 0;
	data->parsing.trimed = 0;
	data->parsing.file = build_file(fd);
	while (data->parsing.file[i] && data->parsing.nbr_info < 6)
	{
		str = ft_strtrim(data->parsing.file[i], " \t");
		if (take_information(str, &data->parsing))
			return (EXIT_FAILURE);
		free(str);
		i++;
	}
	while (data->parsing.file[i] && data->parsing.trimed == 0)
	{
		if (check_and_trim(data->parsing.file[i], &data->parsing))
			return (EXIT_FAILURE);
		i++;
	}
	data->parsing.map = build_map(&data->parsing.file[i - 1]);
	return (EXIT_SUCCESS);
}

int	parse_map(int argc, char **argv, t_data *data)
{
	int			fd;

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
	if (build_parsing(fd, data))
		return (EXIT_FAILURE);
	if (build_player(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
