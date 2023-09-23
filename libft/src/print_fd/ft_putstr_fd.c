/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:26:23 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/06 01:21:31 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Outputs the string 's' to the file descriptor 'fd'.
 * 
 * @param s The string 's' to output.
 * @param fd The file descriptor 'fd'.
 */
void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
