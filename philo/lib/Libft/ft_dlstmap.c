/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:20:23 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/20 13:44:58 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list LST and applies the function F to the
   content of each node. Applies the function DEL if needed.
   The result is returned in a new list.  */
t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new_list;
	t_dlist	*node;
	void	*cont;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		cont = f(lst->content);
		node = ft_dlstnew(cont);
		if (!node || !cont)
		{
			free(cont);
			free(node);
			ft_dlstclear(&new_list, del);
			return (NULL);
		}
		ft_dlstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
