/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:03:16 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:12:21 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fill a byte string with a byte value.
 * 
 * @param s Pointer to destination memory area where characters will be initialised whith 'c'.
 * @param c The characters 'c' to copy.
 * @param n The maximum number of characters to copy.
 * @return The memory area 's'.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
