/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:59:55 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/30 14:09:49 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_table(
	t_table *table,
	size_t philos_count,
	t_mseconds time_to_die,
	t_mseconds time_to_eat,
	t_mseconds time_to_sleep,
	long meals_count)
{
	size_t	i;

	table->philos_count = philos_count;
	table->time_to_die = time_to_die;
	table->time_to_eat = time_to_eat;
	table->time_to_sleep = time_to_sleep;
	pthread_mutex_init(&table->write_mutex, NULL);
	table->forks = init_forks(table->philos_count);
	table->dead_philo = NULL;
	table->philos = init_philos(table, meals_count);
	if (table->philos)
	{
		i = -1;
		while (++i < table->philos_count)
			table->philos[i].write_mutex = &table->write_mutex;
	}
	if (!table->forks || !table->philos)
		return (0);
	return (1);
}

void	clear_table(
	t_table *table)
{
	clear_forks(table->forks, table->philos_count);
	clear_philos(table->philos);
	pthread_mutex_destroy(&table->write_mutex);
	memset(table, 0, sizeof(t_table));
}
