/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/10/11 16:04:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*mapHelper(t_list *lst, void *(*f)(void *))
{
	t_list	*newList;
	t_list	*currNewList;

	while (lst)
	{
		newList = ft_lstnew((*f)(lst->content));
		if (newList)
		{
			lst = lst->next;
			while (lst)
			{
				currNewList = ft_lstnew((*f)(lst->content));
				if (currNewList)
					ft_lstadd_back(&newList, currNewList);
				else
					return (newList);
				lst = lst->next;
			}
		}
		else
			return (newList);
	}
	ft_lstclear(&lst);
	return (newList);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	if (!(lst))
		return (lst);
	return (mapHelper(lst, f);
}
