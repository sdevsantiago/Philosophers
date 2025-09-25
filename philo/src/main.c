/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:51:58 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/25 09:44:10 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(
	int argc,
	char const *argv[])
{
	(void)argc;
	(void)argv;

	size_t			max = 10000;
	t_philo	philo[max];
	size_t			i = 0;

	pthread_mutex_t	write_mutex;
	pthread_mutex_init(&write_mutex, NULL);

	// init philosopher data
	while (i < max)
	{
		memset(&philo[i], 0, sizeof(t_philo));
		philo[i].id = i + 1;
		pthread_mutex_init(&philo[i].left_fork, NULL); // mutex, attribute (fast mutex as default)
		philo[i].write_mutex = &write_mutex;
		i++;
	}
	i = 1;
	while (i < max)
	{
		philo[i].right_fork = &philo[i - 1].left_fork;
		i++;
	}
	philo[0].right_fork = &philo[i - 1].left_fork;

	// create threads
	i = 0;
	while (i < max)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]) != 0)
		{
			write(STDERR_FILENO, "pthread_create() error\n", 23);
			return (EXIT_FAILURE);
		}
		i++;
	}

	// join threads to execution
	// waits until passed thread terminates to continue with execution, if that thread is already terminated, it continues
	// in reality, this checks if any thread is still alive
	i = 0;
	while (i < max)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}

	return (EXIT_SUCCESS);
}
