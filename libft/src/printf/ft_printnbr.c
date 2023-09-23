/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:24:57 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/06 15:31:06 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Outputs the number 'n' and return the total length of 'n'.
 * 
 * @param n The number 'n' to output.
 * @return Total length of the number 'n'.
 */
int	ft_printnbr(int n)
{
	if (n >= 0)
		return (ft_print_unsigned_int(n));
	ft_putchar_fd('-', STDOUT_FILENO);
	return (1 + ft_print_unsigned_int(-n));
}