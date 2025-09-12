/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:53:49 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 19:18:29 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strisnum(
	const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}
