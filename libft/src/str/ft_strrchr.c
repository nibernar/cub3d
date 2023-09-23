/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:57:56 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 22:45:23 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Find the last occurrence of a given character in a string.
 * 
 * @param s The string 's1' to search.
 * @param c The character 'c' to look for.
 * @return Returns a pointer to the last occurrence of the character. 
 * If character 'c' is not found in the string, the function returns NULL.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)(c))
			return (((char *) s) + i);
		i--;
	}
	return (NULL);
}