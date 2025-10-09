/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/10 09:29:07 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(
	void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->timestamp_death = *philo->timestamp_start + philo->time_to[TIME_DIE];
	if (philo->forks[FORK_LEFT] == philo->forks[FORK_RIGHT])
		msleep(philo, philo->time_to[TIME_DIE]);
	while (1)
	{
		pthread_mutex_lock(&philo->shared_mutexes[SHARED_MUTEX_STOP]);
		if (*philo->stop)
		{
			pthread_mutex_unlock(&philo->shared_mutexes[SHARED_MUTEX_STOP]);
			break ;
		}
		pthread_mutex_unlock(&philo->shared_mutexes[SHARED_MUTEX_STOP]);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

static int	philo_has_starved(t_philo *philo);
static int	all_philos_have_eaten(t_table *table);

void	*waiter_routine(
	void *arg)
{
	t_table	*table;
	size_t	i;

	table = (t_table *)arg;
	while (1)
	{
		i = -1;
		while (++i < table->philos_count)
		{
			if (philo_has_starved(&table->philos[i]))
			{
				threads_stop(table);
				write_action(&table->philos[i], "has died");
				return (NULL);
			}
		}
		if (all_philos_have_eaten(table))
		{
			threads_stop(table);
			break ;
		}
	}
	return (NULL);
}

static int	philo_has_starved(
	t_philo *philo)
{
	if (get_current_timestamp_ms() > philo->timestamp_death)
		return (1);
	return (0);
}

static int	all_philos_have_eaten(
	t_table *table)
{
	(void)table;
	return (0);
}
