/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:02:50 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:48:02 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if a given character belongs to the ASCII table.
 * 
 * @param c The character to test.
 * @return Returns a nonzero value if the character is belongs to ASCII table,
 * 0 if the character is not belongs to ASCII table.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
