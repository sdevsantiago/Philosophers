/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:49:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 17:49:30 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philosophers(
	char const *argv[],
	t_philosophers *ph)
{
	int	i;

	ft_bzero(ph, sizeof(t_philosophers));
	gettimeofday(&ph->time, NULL);
	ph->philosopher_count = ft_atoi(argv[1]);
	ph->time_to_die = ft_atoi(argv[2]);
	ph->time_to_eat = ft_atoi(argv[3]);
	ph->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		ph->meals_count = ft_atoi(argv[5]);
	ph->philos = (t_philo *)ft_calloc(ph->philosopher_count, sizeof(t_philo));
	if (!ph->philos)
		return ;
	i = 0;
	while (i < ph->philosopher_count)
	{
		ph->philos[i].id = i + 1;
		pthread_mutex_init(&ph->philos[i].fork_left, NULL); // create philosopher's left fork
		pthread_create(&ph->philos[i].thread, NULL, philo_routine, &ph->philos[i].id); // create philosopher
		if (i != 0)
			ph->philos[i].fork_right = &ph->philos[i - 1].fork_left; // assign philosopher's right for as previous philosopher's left fork
		i++;
	}
	if (ph->philosopher_count > 1)
		ph->philos[0].fork_right = &ph->philos[ph->philosopher_count - 1].fork_left; // first's philosopher right fork will be last's philosopher left fork
}
