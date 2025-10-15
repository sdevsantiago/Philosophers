/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:59:56 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/15 10:43:06 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	threads_join(t_table *table);

int	threads_run(
	t_table *table,
	t_routine_func philo_routine,
	t_routine_func waiter_routine)
{
	size_t	i;

	if (pthread_create(&table->waiter, NULL, waiter_routine, table) != 0)
	{
		table_clear(table);
		return (0);
	}
	i = -1;
	table->timestamp_start = get_current_timestamp_ms();
	while (++i < table->philos_count)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				philo_routine, &table->philos[i]) != 0)
		{
			table_clear(table);
			return (0);
		}
	}
	return (threads_join(table));
}

static int	threads_join(
	t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->philos_count)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			return (0);
	}
	return (1);
}

void	threads_stop(
	t_table *table)
{
	pthread_mutex_lock(&table->shared_mutexes[MUTEX_STOP]);
	table->stop = 1;
	pthread_mutex_unlock(&table->shared_mutexes[MUTEX_STOP]);
}
