/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:59:24 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 18:26:09 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstdelone(t_clist *lst, void (*del)(void *))
{
	t_clist	*node;

	if (!lst || !del)
		return ;
	node = lst;
	lst = lst->next;
	del(node->content);
	free(node);
}
