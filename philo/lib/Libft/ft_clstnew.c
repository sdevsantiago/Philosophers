/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:27:02 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 18:28:24 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstnew(void *content)
{
	t_clist	*node;

	node = (t_clist *)malloc(sizeof(t_clist));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = node;
	return (node);
}
