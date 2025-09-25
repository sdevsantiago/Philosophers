/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:40:36 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 19:52:02 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlstdelone(t_cdlist *lst, void (*del)(void *))
{
	t_cdlist	*node;

	if (!lst || !del)
		return ;
	node = lst;
	lst = lst->next;
	del(node->content);
	free(node);
}
