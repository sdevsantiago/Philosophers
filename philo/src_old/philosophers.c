/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:10:56 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 17:55:19 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	run_philosophers(t_philosophers *philo);
static void	*philo_routine(void	*arg);
static void	clear_philosophers(t_philosophers *philo);

static void	run_philosophers(
	t_philosophers *ph)
{
	t_philo	*dead;
	int		i;

	i = 0;
	while (i < ph->philosopher_count)
	{
		// pthread_join(ph->philos[i].thread, NULL); // start philosopher
		i++;
	}
	dead = NULL;
	while (1)
	{
		if (dead)
			break ; // end loop if a philosopher died
		if (ph->meals_count)
		{
			ph->meals_count--;
			if (!ph->meals_count)
				break ; // end loop if there is nothing else to eat
		}
	}
	if (dead)
		log_status(dead);
}

/**
 * @brief Philosopher thread routine that defines the behavior of each philosopher.
 *
 * This function serves as the entry point for each philosopher thread and implements
 * the dining philosophers algorithm. Each philosopher will continuously cycle through
 * the states of thinking, eating, and sleeping according to the problem constraints.
 *
 * The routine handles:
 * - Fork acquisition and release
 * - Eating process with timing constraints
 * - Sleeping and thinking phases
 * - Death checking and simulation termination
 * - Thread synchronization with other philosophers
 *
 * 1. eat
 * 2. sleep
 * 3. think
 *
 * @param arg Pointer to the philosopher structure containing thread-specific data
 *            including philosopher ID, fork references, and shared simulation state
 * @return void* Always returns NULL upon thread completion or termination
 */
static void	*philo_routine(
	void	*arg)
{
	(void)arg;
	return (NULL);
}

static void	clear_philosophers(
	t_philosophers *ph)
{
	int	i;

	i = 0;
	while (i < ph->philosopher_count)
	{
		pthread_mutex_destroy(&ph->philos[i].fork_left);
		ft_bzero(&ph->philos[i], sizeof(t_philo));
		free(&ph->philos[i]);
		i++;
	}
	ft_bzero(ph, sizeof(t_philosophers *));
}
