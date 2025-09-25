/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:44:17 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/20 12:46:34 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Frees the node LST content using the function DEL.  */
void	ft_dlstdelone(t_dlist *lst, void (*del)(void *))
{
	t_dlist	*node;

	if (!lst || !del)
		return ;
	node = lst;
	lst = lst->next;
	lst->previous = node->previous;
	del(node->content);
	free(node);
}
