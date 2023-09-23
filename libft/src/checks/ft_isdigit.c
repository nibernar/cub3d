/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:02:55 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:48:05 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the character is a digital character.
 * 
 * @param c The character to test.
 * @return Returns a nonzero value if the character is a digital character,
 * 0 if the character is not digital.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
