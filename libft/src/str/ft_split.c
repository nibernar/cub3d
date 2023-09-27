/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:16:44 by nibernar          #+#    #+#             */
/*   Updated: 2023/09/26 17:18:29 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free_malloc(char **tab, int i);
static int	ft_words_size(char const *s, char c);
static char	**ft_create_words_tab(const char *s, char **tab, char c, int i);

/**
 * @brief Allocates and returns an array of 'new' strings, the character 'c' as a delimiter.
 * If the allocation fails the function returns NULL.
 * 
 * @param s The string 's' to split.
 * @param c The separating character 'c'.
 * @return The new array of strings.
 */
char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_calloc(sizeof(char *), (ft_words_size(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_create_words_tab(s, tab, c, 0));
}

static int	ft_free_malloc(char **tab, int i)
{
	if (!tab[i])
	{
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
		free(tab);
		return (1);
	}
	return (0);
}

static int	ft_words_size(char const *s, char c)
{
	int	i;
	int	words_size;

	i = 0;
	words_size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		words_size++;
	}
	return (words_size);
}

static char	**ft_create_words_tab(const char *s, char **tab, char c, int i)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
				i++;
		if (s[i] == '\0')
			break ;
		index = i;
		while (s[index] && s[index] != c)
			index++;
		tab[j] = ft_substr(s, i, (index - i));
		if (j <= ft_words_size(s, c) && ft_free_malloc(tab, j))
			return (0);
		j++;
		i = index;
	}
	return (tab);
}
