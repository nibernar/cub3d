/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:09:26 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/06 01:21:14 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Outputs the char 'c' to the file descriptor 'fd'.
 * 
 * @param c The characters 'c' to output.
 * @param fd The file descriptor 'fd'.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
