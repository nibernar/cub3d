/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:35:27 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:31:44 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare byte string.
 * 
 * @param s1 Pointer to first string to compare.
 * @param s2 Pointer to the second string to compare.
 * @param n The maximum number of characters to compare.
 * @return Return 0 if the first n characters of the strings are identical, 
 * or a value other than 0 if the two strings are not identical.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uns1;
	unsigned char	*uns2;

	i = 0;
	uns1 = ((unsigned char *) s1);
	uns2 = ((unsigned char *) s2);
	while ((uns1[i] != '\0' || uns2[i] != '\0') && i < n)
	{
		if (uns1[i] != uns2[i])
			return (uns1[i] - uns2[i]);
		i++;
	}
	return (0);
}
