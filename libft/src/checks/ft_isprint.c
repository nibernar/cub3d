/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:03:00 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:48:09 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if a given character is printable character.
 * 
 * @param c The character to test.
 * @return Returns a nonzero value if the character is printable character,
 * 0 if the character is not printable character.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
