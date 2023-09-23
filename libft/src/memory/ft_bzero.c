/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:02:32 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:47:42 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes 'n' zeroed bytes to the string 's'.  If 'n' is zero, ft_bzero does nothing.
 * 
 * @param s Pointer to the string to convert.
 * @param n The number of zeros to put in the string 's'
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
