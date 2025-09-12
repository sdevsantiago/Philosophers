/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:07:08 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 00:40:22 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_memset(
	void *s,
	int c,
	size_t n)
{
	char	*s_ptr;
	size_t	i;

	s_ptr = s;
	i = 0;
	while (i < n)
	{
		s_ptr[i] = c;
		i++;
	}
	return (s);
}
