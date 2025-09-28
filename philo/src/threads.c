/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:59:56 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/28 19:03:31 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	i = -1;
	while (++i < table->philos_count)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
		{
			write(STDERR_FILENO, "pthread_join() error\n", 21);
			return (0);
		}
	}
	return (1);
}
