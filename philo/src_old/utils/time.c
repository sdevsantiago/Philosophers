/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 02:16:39 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 18:23:22 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Converts a timeval structure to milliseconds.
 *
 * This function takes a pointer to a struct timeval and calculates the total
 * number of milliseconds represented by the structure. It multiplies the
 * seconds field by 1000 and adds the microseconds field divided by 1000.
 *
 * @param time Pointer to a struct timeval containing the time to convert.
 *
 * @return The total time in milliseconds.
 */
long	time_to_ms(
	struct timeval *time)
{
	return (time->tv_sec * 1000 + time->tv_usec / 1000);
}
