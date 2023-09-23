/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:35:49 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/04 19:47:50 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Free an array of elements.
 * 
 * @param ptr The array of elements.
 */
void	ft_free(void *ptr)
{
	if (ptr == NULL)
		return ;
	free(ptr);
	ptr = NULL;
}