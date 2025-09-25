/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:24:30 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/20 13:25:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Measures a list.  */
int	ft_dlstsize(t_dlist *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
