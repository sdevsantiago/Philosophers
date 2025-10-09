/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:04:21 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/09 22:10:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*forks_init(
	size_t philos_count)
{
	pthread_mutex_t	*forks;
	size_t			i;

	forks = (pthread_mutex_t *)malloc(philos_count * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	i = -1;
	memset(forks, 0, philos_count * sizeof(pthread_mutex_t));
	while (++i < philos_count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			forks_clear(forks, i);
			return (NULL);
		}
	}
	return (forks);
}

void	forks_clear(
	pthread_mutex_t *forks,
	size_t philos_count)
{
	while (--philos_count)
		pthread_mutex_destroy(&forks[philos_count]);
	free(forks);
}

void	forks_take(
	t_philo *philo)
{
	pthread_mutex_lock(philo->forks[FORK_LEFT]);
	write_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->forks[FORK_RIGHT]);
	write_action(philo, "has taken a fork");
}

void	forks_drop(
	t_philo *philo)
{
	pthread_mutex_unlock(philo->forks[FORK_LEFT]);
	pthread_mutex_unlock(philo->forks[FORK_RIGHT]);
}
