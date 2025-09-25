/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:30:04 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 18:52:01 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_clstsize(t_clist *lst)
{
	int		size;
	t_clist	*first;

	if (!lst)
		return (0);
	size = 0;
	first = lst;
	while (lst)
	{
		size++;
		if (lst->next == first)
			break ;
		lst = lst->next;
	}
	return (size);
}
