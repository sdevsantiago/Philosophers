/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:45:37 by sede-san          #+#    #+#             */
/*   Updated: 2025/04/21 21:24:01 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cdlstsize(t_cdlist *lst)
{
	int			size;
	t_cdlist	*first;

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
