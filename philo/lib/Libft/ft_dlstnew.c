/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:51:08 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/20 09:51:33 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates a new list with the value CONTENT.  */
t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*node;

	node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
