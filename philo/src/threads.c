/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:59:56 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/30 14:09:42 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	join_threads(t_table *table);

int	init_threads(
	t_table *table,
	t_routine_func routine)
{
	size_t	i;

	i = -1;
	table->timestamp_start = get_current_timestamp_ms();
	while (++i < table->philos_count)
	{
		if (pthread_create(&table->philos[i].thread, NULL, routine, &table->philos[i]) != 0)
		{
			write(STDERR_FILENO, "pthread_create() error\n", 23);
			return (0);
		}
	}
	return (join_threads(table));
}

static int	join_threads(
	t_table *table)
{
	size_t	i;
	t_philo	*dead_philo;

	i = -1;
	dead_philo = NULL;
	while (++i < table->philos_count && !dead_philo)
	{
		if (pthread_join(table->philos[i].thread, (void **)&dead_philo) != 0)
		{
			write(STDERR_FILENO, "pthread_join() error\n", 21);
			return (0);
		}
	}
	if (dead_philo)
	{
		msleep(1);
		write_action(dead_philo, "has died");
	}
	return (1);
}
