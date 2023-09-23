/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:24:57 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/06 15:30:01 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Outputs the string 's' to the file descriptor STDOUT and return the total length of 's'.
 * 
 * @param s The string 's' to output.
 * @return Total length of the number 's'.
 */
int	ft_printstr(char *s)
{
	if (!s)
    {
        ft_putstr_fd(STR_NULL, STDOUT_FILENO);    
		return ((int)ft_strlen(STR_NULL));
    }
    ft_putstr_fd(s, STDOUT_FILENO);    
    return ((int)ft_strlen(s));
}
