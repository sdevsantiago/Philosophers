/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:42:57 by sede-san          #+#    #+#             */
/*   Updated: 2025/01/22 19:31:45 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cdlist	*ft_cdlstlast(t_cdlist *lst)
{
	if (!lst)
		return (NULL);
	return (lst->previous);
}
