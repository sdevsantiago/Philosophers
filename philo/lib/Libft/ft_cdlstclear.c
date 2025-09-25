/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:35:25 by sede-san          #+#    #+#             */
/*   Updated: 2025/04/21 21:25:03 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cdlstclear(t_cdlist **lst, void (*del)(void*))
{
	t_cdlist	*current;
	t_cdlist	*next;
	t_cdlist	*head;

	if (!lst || !*lst || !del)
		return ;
	head = *lst;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		if (next == head)
			break ;
		current = next;
	}
	*lst = NULL;
}
