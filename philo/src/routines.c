/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/30 20:45:43 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	routine_eat(t_philo *philo);
static int	routine_sleep(t_philo *philo);
static int	routine_think(t_philo *philo);
static int	philo_has_starved(t_philo *philo);

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
	if (philo_has_starved(philo))
		return (PHILO_DIES);
	if (philo->id % 2)	//? may be the cause of the delay
	{
		pthread_mutex_lock(philo->forks[RIGHT_FORK]);
		pthread_mutex_lock(philo->forks[LEFT_FORK]);
	}
	else
	{
		pthread_mutex_lock(philo->forks[LEFT_FORK]);
		pthread_mutex_lock(philo->forks[RIGHT_FORK]);
	}
	if (philo_has_starved(philo))
		return (PHILO_DIES);
	write_action(philo, "has taken a fork");
	write_action(philo, "has taken a fork");
	write_action(philo, "is eating");
	msleep(*philo->time_to_eat);
	philo->timestamp_death = get_current_timestamp_ms() + *philo->time_to_die;
	pthread_mutex_unlock(philo->forks[LEFT_FORK]);
	pthread_mutex_unlock(philo->forks[RIGHT_FORK]);
	if (philo->meals_count != -1)
		philo->meals_count--;
	return (PHILO_LIVES);
}

static int	routine_sleep(
	t_philo *philo)
{
	if (philo_has_starved(philo))
		return (PHILO_DIES);
	write_action(philo, "is sleeping");
	msleep(*philo->time_to_sleep);
	return (PHILO_LIVES);
}

static int	routine_think(
	t_philo *philo)
{
	if (philo_has_starved(philo))
		return (PHILO_DIES);
	write_action(philo, "is thinking");
	return (PHILO_LIVES);
}

static int	philo_has_starved(
	t_philo *philo)
{
	return (get_current_timestamp_ms() > philo->timestamp_death);
}
