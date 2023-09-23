/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:49:04 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:39:38 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the number 'n' to the file descriptor 'fd'.
 * 
 * @param n The number 'n' to output.
 * @param fd The file descriptor 'fd'.
 */
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	nbr = 0;
	if (n < 0)
	{
		nbr = (unsigned int)(n * -1);
		ft_putchar_fd('-', fd);
	}
	else
		nbr = (unsigned int)(n);
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nbr % 10 + '0', fd);
}
