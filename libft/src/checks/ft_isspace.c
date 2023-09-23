/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:07:04 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/04 19:48:12 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the character is a space character.
 * 
 * @param c The character to test.
 * @return Returns a nonzero value if the character is a space character,
 * 0 if the character is not space.
 */
int	ft_isspace(int c)
{
	return (c == '\n' || c == '\r' || c == '\v' || c == '\t' \
			|| c == '\f' || c == ' ');
}