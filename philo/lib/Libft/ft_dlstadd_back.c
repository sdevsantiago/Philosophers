/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:29:15 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/20 13:43:43 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the node NEW to the last position of the list DLST.  */
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*dlst_ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		dlst_ptr = ft_dlstlast(*lst);
		dlst_ptr->next = new;
		new->previous = dlst_ptr;
	}
}
