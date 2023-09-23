/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:23:48 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 22:36:42 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start(char const *s1, char const *set);
static size_t	ft_get_end(char const *s1, char const *set);

/**
 * @brief Allocates and returns a copy of the string 's1' with no spaces at the beginning or end of the string. 
 * The function returns a copy of 's1'. If the allocation fails, the function returns NULL.
 * 
 * @param s1 The string 's1' to trim.
 * @param set The index 'start' where the new string begins.
 * @return The new string or returns NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	return (ft_substr(s1, start, end - start + 1));
}

static size_t	ft_get_start(char const *s1, char const *set)
{
	long long int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

static size_t	ft_get_end(char const *s1, char const *set)
{
	long long int	i;

	i = (long long int)ft_strlen(s1) - 1;
	while (i >= 0 && ft_strrchr(set, s1[i]) != NULL)
		i--;
	return (i);
}
