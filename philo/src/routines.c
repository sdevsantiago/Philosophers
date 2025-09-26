/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/26 20:27:03 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	routine_eat(t_philo *philo);
static void	routine_sleep(t_philo *philo);
static void	routine_think(t_philo *philo);
static void	write_action(t_philo *philo, char const *action);

void	*philo_routine(
	void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// init specific timestamps
	philo->timestamp_death = *philo->timestamp_start + *philo->time_to_die;
	// main philosopher loop
	while (1)
	{
		routine_eat(philo);
		if (!philo->meals_count)
		{
			// write_action(philo, "has finished"); //? Here for debugging purposes
			return (NULL);
		}
		routine_sleep(philo);
		routine_think(philo);
	}
	return (NULL);
}

static void	routine_eat(
	t_philo *philo)
{
	// check if philo has starved to death
	if (get_current_timestamp_ms() >= philo->timestamp_death)
	{
		write_action(philo, "has died");
		exit(EXIT_FAILURE); //! illegal function
	}
	// avoid lock order inversion
	if (philo->id % 2 == 0) // philo's id is even
	{
		pthread_mutex_lock(philo->forks[LEFT_FORK]);
		pthread_mutex_lock(philo->forks[RIGHT_FORK]);
	}
	else // philo's id is odd
	{
		pthread_mutex_lock(philo->forks[RIGHT_FORK]);
		pthread_mutex_lock(philo->forks[LEFT_FORK]);
	}
	write_action(philo, "has taken a fork");
	write_action(philo, "has taken a fork");
	write_action(philo, "is eating");
	msleep(*philo->time_to_eat);
	philo->timestamp_death = get_current_timestamp_ms() + *philo->time_to_die;
	pthread_mutex_unlock(philo->forks[LEFT_FORK]);
	pthread_mutex_unlock(philo->forks[RIGHT_FORK]);
	if (philo->meals_count != -1)
		philo->meals_count--;
	fprintf(stderr, "DEBUG: philo %ld meals left -> %ld\n", philo->id, philo->meals_count);
}

static void	routine_sleep(
	t_philo *philo)
{
	write_action(philo, "is sleeping");
	msleep(*philo->time_to_sleep);
}

static void	routine_think(
	t_philo *philo)
{
	write_action(philo, "is thinking");
}

static void	write_action(
	t_philo *philo,
	char const *action)
{
	char	*msg;
	char	*timestamp;
	char	*id;

	timestamp = ft_ltoa(get_current_timestamp_ms() - *philo->timestamp_start);
	id = ft_uitoa(philo->id);
	msg = ft_strnjoin(6, timestamp, " " , id, " ", action, "\n");
	pthread_mutex_lock(philo->write_mutex);
	ft_putstr(msg);
	pthread_mutex_unlock(philo->write_mutex);
	free(timestamp);
	free(id);
	free(msg);
}
