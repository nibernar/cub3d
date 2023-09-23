/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:32:36 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:49:39 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the node, using the function ’free’:  void free (void *).
 * 
 * @param lst The liste.
 * @param del The function used on each node in the list, or NULL if no function is used.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	if (del)
		(*del)(lst->content);
	free(lst);
}
