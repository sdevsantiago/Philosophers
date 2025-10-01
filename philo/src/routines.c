/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/01 21:38:56 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	routine_eat(t_philo *philo);
static int	routine_sleep(t_philo *philo);
static int	routine_think(t_philo *philo);
static void	take_forks(t_philo *philo);
static void	drops_forks(t_philo *philo);
static int	has_starved(t_philo *philo);

void	*philo_routine(
	void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->timestamp_death = *philo->timestamp_start + *philo->time_to_die;
	while (!philo->dead_philo)
	{
		if (routine_eat(philo) == PHILO_DIES)
			break ;
		else if (!philo->meals_count)
			return (NULL);
		else if (routine_sleep(philo) == PHILO_DIES)
			break ;
		else if (routine_think(philo) == PHILO_DIES)
			break ;
	}
	return (philo);
}

static int	routine_eat(
	t_philo *philo)
{
	if (philo->forks[LEFT_FORK] == philo->forks[RIGHT_FORK])
		msleep(*philo->time_to_die);
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
	msleep(*philo->time_to_eat);
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
	msleep(*philo->time_to_sleep);
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

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->forks[RIGHT_FORK]);
		pthread_mutex_lock(philo->forks[LEFT_FORK]);
	}
	else
	{
		pthread_mutex_lock(philo->forks[LEFT_FORK]);
		pthread_mutex_lock(philo->forks[RIGHT_FORK]);
	}
}

static void	drops_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->forks[LEFT_FORK]);
	pthread_mutex_unlock(philo->forks[RIGHT_FORK]);
}


static int	has_starved(
	t_philo *philo)
{
	return (philo->dead_philo
		|| get_current_timestamp_ms() > philo->timestamp_death);
}
