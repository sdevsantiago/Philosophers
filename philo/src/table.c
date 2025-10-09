/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:59:55 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/09 16:13:12 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	table_init(
	t_table *table,
	size_t philos_count,
	t_mseconds time_to_die,
	t_mseconds time_to_eat,
	t_mseconds time_to_sleep,
	long meals_count)
{
	table->philos_count = philos_count;
	table->time_to_die = time_to_die;
	table->time_to_eat = time_to_eat;
	table->time_to_sleep = time_to_sleep;
	if (pthread_mutex_init(&table->write_mutex, NULL) != 0
		|| pthread_mutex_init(&table->death_mutex, NULL) != 0)
		return (0);
	table->forks = forks_init(table->philos_count);
	table->dead_philo = NULL;
	table->philos = philos_init(table, meals_count);
	if (!table->philos) // no need to check if forks exist
	{
		table_clear(table);
		return (0);
	}
	return (1);
}

void	table_clear(
	t_table *table)
{
	if (table->forks)
		forks_clear(table->forks, table->philos_count);
	if (table->philos)
		philos_clear(table->philos);
	pthread_mutex_destroy(&table->write_mutex);
	pthread_mutex_destroy(&table->death_mutex);
	memset(table, 0, sizeof(t_table));
}
