/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:42:42 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 19:52:06 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlstiter(t_cdlist *lst, void (*f)(void *))
{
	t_cdlist	*first;

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
