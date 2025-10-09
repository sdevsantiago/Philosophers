/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:04:24 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/09 16:23:47 by sede-san         ###   ########.fr       */
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
		philos[i].time_to_die = &table->time_to_die;
		philos[i].time_to_eat = &table->time_to_eat;
		philos[i].time_to_sleep = &table->time_to_sleep;
		philos[i].meals_count = meals_count;
		philos[i].write_mutex = &table->write_mutex;
		philos[i].death_mutex = &table->death_mutex;
		philos[i].forks[LEFT_FORK] = &table->forks[i];
		philos[i].forks[RIGHT_FORK]
			= &table->forks[(i + table->philos_count - 1) % table->philos_count];
		philos[i].dead_philo = &table->dead_philo;
	}
	return (philos);
}

void	philos_clear(
	t_philo *philos)
{
	free(philos);
	philos = NULL;
}

int	philo_eat(
	t_philo *philo)
{
	if (philo->forks[LEFT_FORK] == philo->forks[RIGHT_FORK])
		msleep(philo, *philo->time_to_die);
	if (has_starved(philo))
		return (PHILO_DIES);
	forks_take(philo);
	if (has_starved(philo))
	{
		forks_drop(philo);
		return (PHILO_DIES);
	}
	philo->timestamp_death = get_current_timestamp_ms() + *philo->time_to_die;
	write_action(philo, "is eating");
	if (!msleep(philo, *philo->time_to_eat))
	{
		forks_drop(philo);
		return (PHILO_DIES);
	}
	forks_drop(philo);
	if (philo->meals_count != -1)
		philo->meals_count--;
	return (PHILO_LIVES);
}

int	philo_sleep(
	t_philo *philo)
{
	if (has_starved(philo))
		return (PHILO_DIES);
	write_action(philo, "is sleeping");
	msleep(philo, *philo->time_to_sleep);
	return (PHILO_LIVES);
}

int	philo_think(
	t_philo *philo)
{
	if (has_starved(philo))
		return (PHILO_DIES);
	write_action(philo, "is thinking");
	return (PHILO_LIVES);
}
