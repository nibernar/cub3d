/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:03:11 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:14:02 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy a region of memory from a source address to a destination address, 
 * even if these two regions overlap, thus avoiding data corruption issues 
 * that might occur with 'ft_memcpy'.
 * 
 * @param dest Pointer to destination memory area where characters will be copied.
 * @param src Pointer to source memory area to copy.
 * @param n The maximum number of characters to copy.
 * @return The memory area 'dest'.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src < dest)
	{
		while (n-- > i)
			((char *)dest)[n] = ((char *)src)[n];
	}
	else if (src > dest)
	{
		while (n > i)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
