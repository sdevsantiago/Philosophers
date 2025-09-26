/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:13:10 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/26 02:40:47 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static pthread_mutex_t	*init_forks(size_t philos_count);
static t_philo			*init_philos(t_table *table, long meals_count);

int init_table(t_table *table)
{
	size_t	i;

	table->philos_count = 20000;
	table->time_to_die = 1000;
	table->time_to_eat = 10;
	table->time_to_sleep = 100;
	pthread_mutex_init(&table->write_mutex, NULL);
	table->forks = init_forks(table->philos_count);
	table->philos = init_philos(table, -1);
	if (table->philos)
	{
		i = -1;
		while(++i < table->philos_count)
			table->philos[i].write_mutex = &table->write_mutex;
	}
	return (table->forks && table->philos) ? 1 : 0;
}

int	init_threads(
	t_table *table,
	t_routine_func routine)
{
	size_t	i;

	i = -1;
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

static pthread_mutex_t	*init_forks(
	size_t philos_count)
{
	pthread_mutex_t	*forks;
	size_t			i;

	forks = (pthread_mutex_t *)malloc(philos_count * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	i = -1;
	while (i < philos_count)
	{
		memset(&forks[i], 0, sizeof(pthread_mutex_t));
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			clear_forks(i, forks);
			write(STDERR_FILENO, "pthread_mutex_init() error\n", 27);
			return (NULL);
		}
		++i;
	}
	return (forks);
}

static t_philo	*init_philos(
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
		philos[i].time_to_die = table->time_to_die;
		philos[i].time_to_eat = table->time_to_eat;
		philos[i].time_to_sleep = table->time_to_sleep;
		philos[i].meals_count = meals_count;
		philos[i].write_mutex = &table->write_mutex;
		philos[i].forks[LEFT_FORK] = &table->forks[i];
		philos[i].forks[RIGHT_FORK] =
			&table->forks[(i + table->philos_count - 1) % table->philos_count];
	}
	return (philos);
}
