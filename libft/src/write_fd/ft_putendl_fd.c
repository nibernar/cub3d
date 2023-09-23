/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:44:40 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:38:53 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the string 's' to the file descriptor 'fd', followed by a ’\n’.
 * 
 * @param s The string 's' to output.
 * @param fd The file descriptor 'fd'.
 */
void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}
