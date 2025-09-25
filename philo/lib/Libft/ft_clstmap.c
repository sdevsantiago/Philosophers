/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:17:10 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/05 10:12:13 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstmap(t_clist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_clist	*new_list;
	t_clist	*node;
	t_clist	*first;

	if (!lst)
		return (NULL);
	new_list = NULL;
	first = lst;
	while (lst)
	{
		node = ft_clstnew(f(lst->content));
		if (!node || !node->content)
		{
			ft_clstdelone(node, del);
			ft_clstclear(&new_list, del);
			return (NULL);
		}
		ft_clstadd_back(&new_list, node);
		if (lst->next == first)
			break ;
		lst = lst->next;
	}
	return (new_list);
}
