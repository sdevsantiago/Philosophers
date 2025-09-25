/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:15:58 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/05 21:46:27 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node `new` to the head of the list `lst`.
 * @attention If `lst` is empty, `new` will be it's only node, ponting in both
 * ways to itself.
 * @param lst The list.
 * @param new The node to add.
 */
void	ft_cdlstadd_front(t_cdlist **lst, t_cdlist *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->previous = new;
		return ;
	}
	new->next = *lst;
	new->previous = ft_cdlstlast(*lst);
	ft_cdlstlast(*lst)->next = new;
	(*lst)->previous = new;
	*lst = new;
}
