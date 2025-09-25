/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:08:58 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/05 23:31:41 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlstadd_back(t_cdlist **lst, t_cdlist *new)
{
	t_cdlist	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->previous = new;
	}
	else
	{
		last = ft_cdlstlast(*lst);
		last->next = new;
		new->next = *lst;
		new->previous = last;
		(*lst)->previous = new;
	}
}
