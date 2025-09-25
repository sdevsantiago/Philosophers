/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:00:34 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 19:08:46 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cdlist	*ft_cdlstnew(void *content)
{
	t_cdlist	*node;

	node = (t_cdlist *)malloc(sizeof(t_cdlist));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = node;
	node->previous = node;
	return (node);
}
