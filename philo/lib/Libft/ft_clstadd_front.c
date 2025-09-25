/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:27:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 18:26:03 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstadd_front(t_clist **lst, t_clist *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	(ft_clstlast(*lst))->next = new;
	*lst = new;
}
