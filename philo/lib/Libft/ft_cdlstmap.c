/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:50:18 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/05 10:07:52 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cdlist	*ft_cdlstmap(t_cdlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_cdlist	*new_list;
	t_cdlist	*node;
	t_cdlist	*first;

	if (!lst)
		return (NULL);
	new_list = NULL;
	first = lst;
	while (lst)
	{
		node = ft_cdlstnew(f(lst->content));
		if (!node || !node->content)
		{
			ft_cdlstdelone(node, del);
			ft_cdlstclear(&new_list, del);
			return (NULL);
		}
		ft_cdlstadd_back(&new_list, node);
		if (lst->next == first)
			break ;
		lst = lst->next;
	}
	return (new_list);
}
