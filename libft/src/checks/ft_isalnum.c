/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:02:38 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:47:54 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the character is an alphanumeric character.
 * 
 * @param c The character to test.
 * @return Returns a nonzero value if the character is an alphanumeric character,
 * 0 if the character is not alphanumeric.
 */
int	ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}
