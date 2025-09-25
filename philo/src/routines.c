/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:50:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/25 09:44:10 by sede-san         ###   ########.fr       */
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
	// main philosopher loop
	while (1)
	{
		routine_eat(philo);
		routine_sleep(philo);
		routine_think(philo);
	}
	return (NULL);
}

static void	routine_eat(
	t_philo *philo)
{
	// avoid lock order inversion
	if (philo->id % 2 == 0) // philo's id is even
	{
		pthread_mutex_lock(&philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else // philo's id is odd
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&philo->left_fork);
	}
	write_action(philo, "has taken a fork");
	write_action(philo, "has taken a fork");
	write_action(philo, "is eating");
	usleep(10);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	routine_sleep(
	t_philo *philo)
{
	write_action(philo, "is sleeping");
	usleep(100);
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
	char	*id;

	id = ft_uitoa(philo->id);
	msg = ft_strnjoin(4, id, " ", action, "\n");
	pthread_mutex_lock(philo->write_mutex);
	ft_putstr(msg);
	pthread_mutex_unlock(philo->write_mutex);
	free(id);
	free(msg);
}
