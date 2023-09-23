/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:41:38 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/23 19:04:15 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ft_next_buff(char *buffer);
static char	*ft_select_line(char *buffer);
static char	*ft_read(int fd, char *buffer);

/**
 * @brief Returns a line read from a file descriptor.
 * 
 * @param fd The file descriptor.
 * @return A 'new' string.
 */
char	*ft_get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (ft_free(buffer), NULL);
	str = ft_select_line(buffer);
	if (!str)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_next_buff(buffer);
	return (str);
}

static char	*ft_next_buff(char *buffer)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	len = -1;
	while (buffer[++len])
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (len - i + 1));
	i++;
	if (!str)
		return (ft_free(buffer), NULL);
	else
		while (i < len && buffer != NULL && buffer[i])
			str[j++] = buffer[i++];
	ft_free (buffer);
	return (str);
}

static char	*ft_select_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = buffer[i];
	return (str);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*tmp;
	int		flag;

	tmp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	flag = 1;
	while (flag > 0)
	{
		flag = read(fd, tmp, BUFFER_SIZE);
		if (flag == -1)
		{
			free(tmp);
			return (ft_free(buffer), NULL);
		}
		if (flag < BUFFER_SIZE)
			return (end_of_file(buffer, tmp, flag));
		buffer = add_and_clean_buf(buffer, tmp);
		if (ft_strchr(buffer, '\n'))
		{
			free(tmp);
			break ;
		}
	}
	return (buffer);
}
