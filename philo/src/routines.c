/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/30 14:09:58 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	routine_eat(t_philo *philo);
static void	routine_sleep(t_philo *philo);
static void	routine_think(t_philo *philo);

void	*philo_routine(
	void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->timestamp_death = *philo->timestamp_start + *philo->time_to_die;
	while (!philo->dead_philo)
	{
		if (routine_eat(philo) == PHILO_STARVES)
			break ;
		else if (!philo->meals_count)
			return (NULL);
		routine_sleep(philo);
		routine_think(philo);
	}
	return (philo);
}

static int	routine_eat(
	t_philo *philo)
{
	if (philo->forks[LEFT_FORK] == philo->forks[RIGHT_FORK])
		msleep(*philo->time_to_die);
	if (get_current_timestamp_ms() >= philo->timestamp_death)
		return (PHILO_STARVES);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->forks[LEFT_FORK]);
		pthread_mutex_lock(philo->forks[RIGHT_FORK]);
	}
	else
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
	return (PHILO_LIVES);
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
