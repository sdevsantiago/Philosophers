/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:52:21 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/26 20:25:10 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	clear_forks(pthread_mutex_t *forks, size_t philos_count);
static void clear_philos(t_philo *philos);

void	clear_table(
	t_table *table)
{
	clear_forks(table->forks, table->philos_count);
	clear_philos(table->philos);
	pthread_mutex_destroy(&table->write_mutex);
	memset(table, 0, sizeof(t_table));
}

static void	clear_forks(
	pthread_mutex_t *forks,
	size_t philos_count)
{
	while (--philos_count)
		pthread_mutex_destroy(&forks[philos_count]);
	free(forks);
}

static void clear_philos(
	t_philo *philos)
{
	free(philos);
}
