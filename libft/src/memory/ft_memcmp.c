/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:45:34 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:15:38 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare byte memory area.
 * 
 * @param s1 Pointer to first memory area to compare.
 * @param s2 Pointer to the second memory area to compare.
 * @param n The maximum number of characters to compare.
 * @return Return 0 if the first n characters of the memory areas are identical, 
 * or a value other than 0 if the two memory areas are not identical.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = ((unsigned char *) s1);
	str2 = ((unsigned char *) s2);
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
