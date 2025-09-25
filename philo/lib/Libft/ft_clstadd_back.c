/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:19:03 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 19:13:31 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstadd_back(t_clist **lst, t_clist *new)
{
	t_clist	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_clstlast(*lst);
		last->next = new;
		new->next = *lst;
	}
}
