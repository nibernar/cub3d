/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:24:57 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/06 15:28:04 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Outputs the pointer of the variable 'n' to the file descriptor STDOUT and return the total length of 'nb'.
 * 
 * @param nb The pointer of the variable 'n'.
 * @param base The hexadecimal 'base'.
 * @return Total length of the pointer 'n'.
 */
int	ft_print_pointer(unsigned long n, char *base)
{
	int	len;

	len = 1;
	if (n >= 16)
		len += ft_print_pointer(n / 16, base);
	ft_putchar_fd(base[n % 16], STDOUT_FILENO);
	return (len);
}