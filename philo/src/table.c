/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:59:55 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/15 21:32:34 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	table_init(
	t_table *table,
	char const *argv[])
{
	long	meals_count;

	memset(table, 0, sizeof(t_table));
	table->philos_count = ft_atol(argv[1]);
	table->time_to[TIME_DIE] = ft_atoi(argv[2]);
	table->time_to[TIME_EAT] = ft_atoi(argv[3]);
	table->time_to[TIME_SLEEP] = ft_atoi(argv[4]);
	if (pthread_mutex_init(&table->shared_mutexes[MUTEX_WRITE], NULL) != 0
		|| pthread_mutex_init(&table->shared_mutexes[MUTEX_STOP], NULL) != 0)
		return (0);
	table->forks = forks_init(table->philos_count);
	meals_count = INFINITE_MEALS;
	if (argv[5])
		meals_count = ft_atol(argv[5]);
	table->philos = philos_init(table, meals_count);
	if (!table->philos)
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
	pthread_mutex_destroy(&table->shared_mutexes[MUTEX_WRITE]);
	pthread_mutex_destroy(&table->shared_mutexes[MUTEX_STOP]);
	memset(table, 0, sizeof(t_table));
}
