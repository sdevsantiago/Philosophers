/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:29:00 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 18:16:32 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstiter(t_clist *lst, void (*f)(void *))
{
	t_clist	*first;

	if (!lst || !f)
		return ;
	first = lst;
	while (lst)
	{
		f(lst->content);
		if (lst->next == first)
			break ;
		lst = lst->next;
	}
}
