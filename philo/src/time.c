/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:20:17 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/26 02:02:29 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	micros_to_ms(struct timeval *time);

long	get_current_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (micros_to_ms(&time));
}

static long	micros_to_ms(
	struct timeval *time)
{
	return ((time->tv_sec * 1000) + (time->tv_usec / 1000));
}
