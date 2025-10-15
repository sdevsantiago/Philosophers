/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/15 18:46:21 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(
	void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->shared_mutexes[MUTEX_STOP]);
	philo->timestamp_death = *philo->timestamp_start + philo->time_to[TIME_DIE];
	pthread_mutex_unlock(&philo->shared_mutexes[MUTEX_STOP]);
	if (philo->forks[FORK_LEFT] == philo->forks[FORK_RIGHT])
	{
		write_action(philo, "has taken a fork");
		msleep(philo, philo->time_to[TIME_DIE] + 1);
	}
	else if (!(philo->id % 2))
		usleep(10);
	while (!philo_has_starved(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

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

int	philo_has_starved(
	t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_mutexes[MUTEX_STOP]);
	if (*philo->stop)
	{
		pthread_mutex_unlock(&philo->shared_mutexes[MUTEX_STOP]);
		return (1);
	}
	if (get_current_timestamp_ms() > philo->timestamp_death)
	{
		if (!*philo->stop)
			*philo->stop = 1;
		pthread_mutex_unlock(&philo->shared_mutexes[MUTEX_STOP]);
		return (1);
	}
	pthread_mutex_unlock(&philo->shared_mutexes[MUTEX_STOP]);
	return (0);
}

static int	all_philos_have_eaten(
	t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->philos_count)
	{
		pthread_mutex_lock(&table->shared_mutexes[MUTEX_STOP]);
		if (table->philos[i].meals_count != 0)
		{
			pthread_mutex_unlock(&table->shared_mutexes[MUTEX_STOP]);
			break;
		}
		pthread_mutex_unlock(&table->shared_mutexes[MUTEX_STOP]);
	}
	if (i == table->philos_count)
		return (1);
	return (0);
}
