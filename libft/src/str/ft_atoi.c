/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:30:32 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:47:36 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert ASCII string to integer.
 * 
 * @param str The string to convert.
 * @return The new integer, Result of character string conversion.
 */
int	ft_atoi(const char *str)
{
	int			i;
	int			signe;
	long long	result;

	i = 0;
	signe = 0;
	result = 0;
	while (str[i] != '\0' && (ft_isspace((const int)str[i])))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = 1;
		i++;
	}
	while (str[i] && (ft_isdigit((int)str[i])))
	{
		if (ft_isdigit((int)str[i]))
			result = result * 10 + (str[i] - '0');
		i++;
	}
	if (signe)
		result = result * -1;
	return ((int) result);
}
