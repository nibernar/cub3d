/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:54:25 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/23 18:22:13 by nibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Find the first occurrence of a given character in a string.
 * 
 * @param s Pointer to the string 's' in which to search for the character.
 * @param c The character to be searched for in the string.
 * @return A string to the first occurrence of the character. 
 * If character 'c' is not found in the string, the function returns NULL.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && s[i] != (char)(c))
		i++;
	if (s[i] == (char)(c))
		return (((char *)s) + i);
	return (NULL);
}
