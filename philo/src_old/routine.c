/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:12:08 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/08 16:45:51 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	routine_eat(t_philo *philo);
static void	routine_sleep(t_philo *philo);
static void	routine_think(t_philo *philo);

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1) // check if any philosopher is dead
	{
		routine_eat(philo);
		routine_sleep(philo);
		routine_think(philo);
	}
	return (NULL); // to be changed
}

static void	routine_eat(t_philo *philo)
{

}

static void	routine_sleep(t_philo *philo)
{

}

static void	routine_think(t_philo *philo)
{

}
