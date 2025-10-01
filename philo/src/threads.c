/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:59:56 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/01 21:40:00 by sede-san         ###   ########.fr       */
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
		if (pthread_create(&table->philos[i].thread, NULL,
			routine, &table->philos[i]) != 0)
		{
			clear_table(table);
			return (0);
		}
	}
	return (join_threads(table));
}

static int	join_threads(
	t_table *table)
{
	t_philo	*dead_philo;
	size_t	i;

	dead_philo = NULL;
	i = -1;
	while (++i < table->philos_count)
	{
		if (pthread_join(table->philos[i].thread, (void **)&dead_philo) != 0)
			return (0);
		if (!table->dead_philo && dead_philo) //? log first death only
			table->dead_philo = dead_philo;
	}
	if (table->dead_philo)
	{
		printf("%u\n", get_current_timestamp_ms() - dead_philo->timestamp_death);
		write_action(table->dead_philo, "has died");
	}
	return (1);
}
