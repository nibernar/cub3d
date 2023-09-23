/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:10:20 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:50:47 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_len(unsigned int nbr);
static char	*ft_create_str(unsigned int nbr, char *str, int i, unsigned int len);

/**
 * @brief Convert integer to ASCII string.
 * 
 * @param n The integer to convert.
 * @return The new string, Result of integer conversion.
 */
char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	len;
	unsigned int	i;
	int				signe;
	char			*str;

	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)(n);
	signe = 0;
	len = size_len(nbr);
	if (n < 0)
		signe = 1;
	i = 0;
	str = (char *)malloc(sizeof(str) * (len + 1 + signe));
	if (!str)
		return (NULL);
	if (n < 0)
	{
	str[i] = '-';
		len++;
	}
	i = len -1;
	return (ft_create_str(nbr, str, i, len));
}

static int	size_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr >= 10)
	{
		len++;
		nbr /= 10;
	}
	return (len + 1);
}

static char	*ft_create_str(unsigned int nbr, char *str, int i, unsigned int len)
{
	while (nbr >= 10)
	{
		str[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	str[i] = nbr % 10 + '0';
	str[len] = '\0';
	return (str);
}
