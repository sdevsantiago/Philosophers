/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:37:15 by sede-san          #+#    #+#             */
/*   Updated: 2025/07/27 03:21:29 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the minimum of two integer values.
 *
 * This function compares two integers and returns the smaller one.
 *
 * @param a First integer value.
 * @param b Second integer value.
 *
 * @return The smaller of the two integer values.
 */
int	ft_imin(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}
