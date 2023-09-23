/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:05:10 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:33:50 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function 'f' to each character of the string 
 * passed as argument to create a 'new' string.
 * 
 * @param s Pointer to string 's'.
 * @param f The function 'f' to applies.
 * @return A 'new' string ending with ’\0’ or NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (!s)
		return (NULL);
	i = (unsigned int) ft_strlen(s);
	dest = malloc(sizeof(*dest) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
