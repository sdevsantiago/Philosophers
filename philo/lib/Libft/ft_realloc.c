/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 22:19:17 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/25 08:40:36 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void			*new_ptr;

	new_ptr = (void *)malloc(size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memmove(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}
