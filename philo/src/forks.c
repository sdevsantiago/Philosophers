/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:04:21 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/01 19:29:43 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*init_forks(
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
			clear_forks(forks, i);
			return (NULL);
		}
	}
	return (forks);
}

void	clear_forks(
	pthread_mutex_t *forks,
	size_t philos_count)
{
	while (--philos_count)
		pthread_mutex_destroy(&forks[philos_count]);
	free(forks);
}
