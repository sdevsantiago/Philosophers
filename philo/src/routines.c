/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/03 08:45:23 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	routine_eat(t_philo *philo);
static int	routine_sleep(t_philo *philo);
static int	routine_think(t_philo *philo);
static int	has_starved(t_philo *philo);

int	msleep(
	t_philo *philo,
	t_mseconds msec)
{
	const t_mseconds	timestamp_end
		= get_current_timestamp_ms() + msec;

	while (get_current_timestamp_ms() < timestamp_end)
	{
		if (has_starved(philo) && usleep(500) != 0)
			return (0);
	}
	return (1);
}


void	*philo_routine(
	void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->timestamp_death = *philo->timestamp_start + *philo->time_to_die;
	if (philo->forks[LEFT_FORK] == philo->forks[RIGHT_FORK])
		msleep(philo, *philo->time_to_die);
	else if (philo->id % 2)
		usleep(10);
	while (1)
	{
		if (routine_eat(philo) == PHILO_DIES)
			break ;
		else if (!philo->meals_count)
			break ;
		else if (routine_sleep(philo) == PHILO_DIES)
			break ;
		else if (routine_think(philo) == PHILO_DIES)
			break ;
	}
	return (NULL);
}

static int	routine_eat(
	t_philo *philo)
{
	if (philo->forks[LEFT_FORK] == philo->forks[RIGHT_FORK])
		msleep(philo, *philo->time_to_die);
	if (has_starved(philo))
		return (PHILO_DIES);
	take_forks(philo);
	if (has_starved(philo))
	{
		drops_forks(philo);
		return (PHILO_DIES);
	}
	philo->timestamp_death = get_current_timestamp_ms() + *philo->time_to_die;
	write_action(philo, "has taken a fork");
	write_action(philo, "has taken a fork");
	write_action(philo, "is eating");
	if (!msleep(philo, *philo->time_to_eat))
	{
		drops_forks(philo);

	}
	drops_forks(philo);
	if (philo->meals_count != -1)
		philo->meals_count--;
	return (PHILO_LIVES);
}

static int	routine_sleep(
	t_philo *philo)
{
	if (has_starved(philo))
		return (PHILO_DIES);
	write_action(philo, "is sleeping");
	msleep(philo, *philo->time_to_sleep);
	return (PHILO_LIVES);
}

static int	routine_think(
	t_philo *philo)
{
	if (has_starved(philo))
		return (PHILO_DIES);
	write_action(philo, "is thinking");
	return (PHILO_LIVES);
}


static int	has_starved(
	t_philo *philo)
{
	pthread_mutex_lock(philo->death_mutex);
	if (*philo->dead_philo)
	{
		pthread_mutex_unlock(philo->death_mutex);
		return (1);
	}
	else if (get_current_timestamp_ms() > philo->timestamp_death)
	{
		philo->dead_philo = &philo;
		pthread_mutex_unlock(philo->death_mutex);
		write_action(philo, "has died");
		return (1);
	}
	pthread_mutex_unlock(philo->death_mutex);
	return (0);
}
