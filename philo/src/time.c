/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:20:17 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/09 21:17:49 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_mseconds	get_current_timestamp_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	msleep(
	t_philo *philo,
	t_mseconds msec)
{
	const t_mseconds	timestamp_end
		= get_current_timestamp_ms() + msec;

	(void)philo;
	while (get_current_timestamp_ms() < timestamp_end)
	{
		if (usleep(500) != 0)
			return (0);
	}
	return (1);
}
