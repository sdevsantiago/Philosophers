/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/09 16:21:56 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	msleep(
	t_philo *philo,
	t_mseconds msec)
{
	const t_mseconds	timestamp_end
		= get_current_timestamp_ms() + msec;

	while (get_current_timestamp_ms() < timestamp_end)
	{
		if (has_starved(philo) && usleep(500) != 0)
			return (0);
	}
	return (1);
}

void	*philo_routine(
	void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->timestamp_death = *philo->timestamp_start + *philo->time_to_die;
	if (philo->forks[LEFT_FORK] == philo->forks[RIGHT_FORK])
		msleep(philo, *philo->time_to_die);
	while (1)
	{
		if (philo_eat(philo) == PHILO_DIES)
			break ;
		else if (philo_sleep(philo) == PHILO_DIES)
			break ;
		else if (philo_think(philo) == PHILO_DIES)
			break ;
	}
	return (NULL);
}

int	has_starved(
	t_philo *philo)
{
	pthread_mutex_lock(philo->death_mutex);
	if (*philo->dead_philo)
	{
		pthread_mutex_unlock(philo->death_mutex);
		return (1);
	}
	else if (get_current_timestamp_ms() > philo->timestamp_death)
	{
		philo->dead_philo = &philo;
		pthread_mutex_unlock(philo->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->death_mutex);
	return (0);
}
