/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:02:41 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/05 00:45:46 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates a list 'lst' and applies the function 'f' to each link to create a 'new' list 
 * resulting from the successive applications of f. If the allocation fails, the function returns NULL.
 * 
 * @param lst The liste.
 * @param f The function used on each node in the list.
 * @param del The function used on each node in the list if malloc failed.
 * @return the new list.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = 0;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new, (*del));
			break ;
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
