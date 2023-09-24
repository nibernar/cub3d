/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:49:52 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/24 17:42:48 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_struct(t_parsing *parsing)
{
	printf("%s\n", parsing->north_texture);
	printf("%s\n", parsing->south_texture);
	printf("%s\n", parsing->west_texture);
	printf("%s\n", parsing->east_texture);
	printf("%s\n", parsing->floor_color);
	printf("%s\n", parsing->ceiling_color);
}

static int	check_extention(char *str)
{
	str = ft_strrchr(str, '.');
	if (str == NULL)
		return (EXIT_FAILURE);
	if (ft_strncmp(str, ".cub", 4) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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

int		take_path(char *map, t_parsing *parsing, int flag)
{
	if (flag == 1)
		parsing->north_texture = map;
	if (flag == 2)
		parsing->south_texture = map;
	if (flag == 3)
		parsing->west_texture = map;
	if (flag == 4)
		parsing->east_texture = map;
	if (flag == 5)
		parsing->floor_color = map;
	if (flag == 6)
		parsing->ceiling_color = map;
	parsing->nbr_info++;
	return (EXIT_SUCCESS);
}

int	take_information(char *map, t_parsing *parsing)
{
	if ((ft_strlen("NO ./path_to_the_north_texture") == ft_strlen(map)) \
	&& (ft_strncmp("NO ./path_to_the_north_texture", map, 30) == 0))
		return (take_path(map, parsing, 1));
	else if ((ft_strlen("SO ./path_to_the_south_texture") == ft_strlen(map)) \
	&& (ft_strncmp("SO ./path_to_the_south_texture", map, 30) == 0))
		return (take_path(map, parsing, 2));
	else if ((ft_strlen("WE ./path_to_the_west_texture") == ft_strlen(map)) \
	&& (ft_strncmp("WE ./path_to_the_west_texture", map, 29) == 0))
		return (take_path(map, parsing, 3));
	else if ((ft_strlen("EA ./path_to_the_east_texture") == ft_strlen(map)) \
	&& (ft_strncmp("EA ./path_to_the_east_texture", map, 29) == 0))
		return (take_path(map, parsing, 4));
	else if ((ft_strlen("F ") == 2) && (ft_strncmp("F ", map, 2) == 0))
		return (take_path(map, parsing, 5));
	else if ((ft_strlen("C ") == 2) && (ft_strncmp("C ", map, 2) == 0))
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

void	build_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i++]);
		usleep(500000);
	}
}

int build_parsing(int fd, t_parsing *parsing)
{
	char		*str;
	int			i;

	i = 0;
	str = NULL;
	parsing->nbr_info = 0;
	parsing->trimed = 0;
	parsing->file = build_file(fd);
	while (parsing->file[i] && parsing->nbr_info < 6)
	{
		str = ft_strtrim(parsing->file[i], " \t");
		if (take_information(str, parsing))
			return (EXIT_FAILURE);
		i++;
	}
	while (parsing->file[i] && parsing->trimed == 0)
	{
		if (check_and_trim(parsing->file[i], parsing))
			return (EXIT_FAILURE);
		i++;
	}
	build_map(&parsing->file[i - 1]);
	//print_struct(parsing);
	return (EXIT_SUCCESS);
}

int	parse_map(int argc, char **argv, t_data *data)
{
	t_parsing	parsing;
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
	if (build_parsing(fd, &parsing))
		printf("helo\n");
	//if (check_args_map())
	return (EXIT_SUCCESS);
}
