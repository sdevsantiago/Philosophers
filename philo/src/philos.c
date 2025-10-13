/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:04:24 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/13 19:29:18 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philos_init(
	t_table *table,
	long meals_count)
{
	t_philo	*philos;
	size_t	i;

	if (!table->forks)
		return (NULL);
	philos = (t_philo *)malloc(table->philos_count * sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = -1;
	while (++i < table->philos_count)
	{
		philos[i].id = i + 1;
		philos[i].timestamp_start = &table->timestamp_start;
		philos[i].time_to = table->time_to;
		philos[i].meals_count = meals_count;
		philos[i].shared_mutexes = table->shared_mutexes;
		philos[i].forks[FORK_LEFT] = &table->forks[i];
		philos[i].forks[FORK_RIGHT]
			= &table->forks[(i + table->philos_count - 1) % table->philos_count];
		philos[i].stop = &table->stop;
		philos[i].timestamp_death = -1;
	}
	return (philos);
}

void	philos_clear(
	t_philo *philos)
{
	free(philos);
	philos = NULL;
}

void	philo_eat(
	t_philo *philo)
{
	if (philo_has_starved(philo))
		return ;
	forks_take(philo);
	if (philo->forks[FORK_LEFT] != philo->forks[FORK_RIGHT])
	{
		pthread_mutex_lock(&philo->shared_mutexes[SHARED_MUTEX_STOP]);
		philo->timestamp_death
			= get_current_timestamp_ms() + philo->time_to[TIME_DIE];
		pthread_mutex_unlock(&philo->shared_mutexes[SHARED_MUTEX_STOP]);
		write_action(philo, "is eating");
		msleep(philo, philo->time_to[TIME_EAT]);
	}
	else
		msleep(philo, philo->time_to[TIME_DIE]);
	forks_drop(philo);
	pthread_mutex_lock(&philo->shared_mutexes[SHARED_MUTEX_STOP]);
	if (philo->meals_count != -1)
		philo->meals_count--;
	pthread_mutex_unlock(&philo->shared_mutexes[SHARED_MUTEX_STOP]);
}

void	philo_sleep(
	t_philo *philo)
{
	if (philo_has_starved(philo))
		return ;
	write_action(philo, "is sleeping");
	msleep(philo, philo->time_to[TIME_SLEEP]);
}

void	philo_think(
	t_philo *philo)
{
	if (philo_has_starved(philo))
		return ;
	write_action(philo, "is thinking");
}
