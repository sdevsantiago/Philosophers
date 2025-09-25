/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:32:20 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 19:39:13 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstclear(t_clist **lst, void (*del)(void *))
{
	t_clist	*first;
	t_clist	*node;

	if (!lst || !del)
		return ;
	first = *lst;
	while (*lst)
	{
		node = *lst;
		ft_clstdelone(node, del);
		if ((*lst)->next == first)
			break ;
		*lst = (*lst)->next;
	}
}
