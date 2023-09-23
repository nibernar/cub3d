/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:24:57 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/06 15:28:26 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Outputs the number 'nb' to the file descriptor STDOUT and return the total length of 'nb'.
 * 
 * @param nb The number 'n' to output.
 * @return Total length of the number 'nb'.
 */
int	ft_print_unsigned_int(unsigned int nb)
{
	int		len;

	len = 1;
	if (nb > 9)
		len += ft_print_unsigned_int(nb / 10);
	ft_putchar_fd(nb % 10 + '0', STDOUT_FILENO);
	return (len);
}