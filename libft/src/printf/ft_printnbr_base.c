/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:24:57 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/06 15:29:19 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Outputs the number 'n' to the file descriptor 'fd' 
 * with Hexadécimal base and return the total length of 'n'.
 * 
 * @param n The number 'n' to output.
 * @param base The base to convert 'n'.
 * @return Total length of the number 'n'.
 */
int	ft_printnbr_base(int n, char *base)
{
	unsigned int	nbr;
	int				len;

	len = 1;
	nbr = (unsigned int)(n);
	if (nbr >= 16)
		len += ft_printnbr_base(nbr / 16, base);
	ft_putchar_fd(base[nbr % 16], STDOUT_FILENO);
	return (len);
}
