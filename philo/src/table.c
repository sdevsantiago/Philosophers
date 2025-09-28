/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:59:55 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/28 19:11:04 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_table(
	t_table *table)
{
	size_t	i;

	table->philos_count = 10;
	table->time_to_die = 1000;
	table->time_to_eat = 10;
	table->time_to_sleep = 100;
	pthread_mutex_init(&table->write_mutex, NULL);
	table->forks = init_forks(table->philos_count);
	table->philos = init_philos(table, 100);
	if (table->philos)
	{
		i = -1;
		while(++i < table->philos_count)
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

