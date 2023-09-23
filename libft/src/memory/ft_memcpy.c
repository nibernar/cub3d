/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:03:06 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:13:11 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy memory area.
 * 
 * @param dest Pointer to destination memory area where characters will be copied.
 * @param src Pointer to source memory area to copy.
 * @param n The maximum number of characters to copy.
 * @return The memory area 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL && (n > 0))
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
