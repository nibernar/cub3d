/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:57:08 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/04 19:49:31 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the element new at the beginning of the list.
 * 
 * @param lst The liste.
 * @param new The node.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
