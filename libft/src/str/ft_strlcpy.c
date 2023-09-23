/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:30:25 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:20:27 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Size bounded string copy.
 * 
 * @param dest Pointer to destination string where characters will be copied.
 * @param src Pointer to source string to copy.
 * @param n The maximum number of characters to copy.
 * @return The total size of the memory area in the destination string
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (ft_strlen(src));
	if (n != 0)
	{
		while (src[i] != '\0' && (i < n - 1))
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
