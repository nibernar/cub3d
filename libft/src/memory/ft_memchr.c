/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:14:42 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:50:30 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Search for the first occurrence of a specific byte in a given memory area.
 * 
 * @param s Pointer to the beginning of the memory area in which we want to search for the byte.
 * @param c The byte to be searched for in the memory area.
 * @param n The number of bytes to search from pointer 's'.
 * @return The new memory area. or NULL if 'n' is equal to zero.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*str;

	c2 = (unsigned char) c;
	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c2)
			return (str + i);
		i++;
	}
	return (NULL);
}
