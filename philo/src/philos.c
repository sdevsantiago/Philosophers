/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:04:24 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/30 14:10:20 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*init_philos(
	t_table *table,
	long meals_count)
{
	t_philo	*philos;
	size_t	i;

	if (!table->forks)
		return (NULL);
	philos = (t_philo *)malloc(table->philos_count * sizeof(t_philo));
	if (!philos)
	{
		write(STDERR_FILENO, "malloc() error\n", 15);
		return (NULL);
	}
	i = -1;
	while (++i < table->philos_count)
	{
		memset(&philos[i], 0, sizeof(t_philo));
		philos[i].id = i + 1;
		philos[i].timestamp_start = &table->timestamp_start;
		philos[i].time_to_die = &table->time_to_die;
		philos[i].time_to_eat = &table->time_to_eat;
		philos[i].time_to_sleep = &table->time_to_sleep;
		philos[i].meals_count = meals_count;
		philos[i].write_mutex = &table->write_mutex;
		philos[i].forks[LEFT_FORK] = &table->forks[i];
		philos[i].forks[RIGHT_FORK]
			= &table->forks[(i + table->philos_count - 1) % table->philos_count];
		philos[i].dead_philo = table->dead_philo;
	}
	return (philos);
}

void	clear_philos(
	t_philo *philos)
{
	free(philos);
	philos = NULL;
}
