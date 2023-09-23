/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:41:38 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/09/23 19:04:19 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*end_of_file(char *buffer, char *tmp, int flag)
{
	char	*temp;

	tmp[flag] = '\0';
	temp = ft_strjoin_gnl(buffer, tmp);
	ft_free(buffer);
	ft_free(tmp);
	return (temp);
}

char	*add_and_clean_buf(char *buffer, char *tmp)
{
	char	*temp;

	temp = ft_strjoin_gnl(buffer, tmp);
	// printf("buffer => |%s|  tmp => |%s|  temp => |%s|\n", buffer, tmp, temp);
	free(buffer);
	return (temp);
}
