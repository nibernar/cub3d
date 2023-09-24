/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:31:30 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/24 12:34:20 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Search for a string 'to_find' in a string 'str', 
 * but it also adds a search limit to specify the maximum number of characters to examine.
 * 
 * @param str The string 'str' to search.
 * @param to_find The string 'to_find'.
 * @return Returns a pointer to the first occurrence of the character. 
 * If string 'to_find' is not found in the string 'str', the function returns NULL.
 */
char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(to_find) == 0)
		return ((char *) str);
	i = 0;
	while (i < n && str[i])
	{
		j = 0;
		while (to_find[j] && to_find[j] == str[i + j] && (n > i + j))
			j++;
		if (to_find[j] == '\0')
			return ((char *) str + i);
		i++;
	}
	return (NULL);
}
