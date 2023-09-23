/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:53:34 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:47:45 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates dynamic memory for an array of elements of specified size,
 * and initializes all bytes of this memory to zero.
 * 
 * @param count The number of elements to be allocated in the array.
 * @param n Size of each item in bytes.
 * @return An array of elements initialized to zero.
 */
void	*ft_calloc(size_t count, size_t n)
{
	void	*memstr;

	memstr = (void *)malloc(count * n);
	if (!memstr)
		return (NULL);
	ft_bzero(memstr, count * n);
	return (memstr);
}
