/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:10:56 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/24 05:17:53 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static void	init_philosophers(char const *argv[], t_philosophers *philo);
static void	philosophers(t_philosophers *philo);
static void	clear_philosophers(t_philosophers *philo);

int	main(
	int argc,
	char const *argv[])
{
	t_philosophers	ph;

	if ((argc != 4 && argc != 5)
		|| !*argv[1] || !*argv[2] || !*argv[3] || !*argv[4]
		|| (argv[5] && !*argv[5]))
		return (printf("ERROR: Invalid usage\n"), EXIT_FAILURE);
	init_philosophers(argv, &ph);
	philosophers(&ph);
	clear_philosophers(&ph);
	return (EXIT_SUCCESS);
}

static void	init_philosophers(
	char const *argv[],
	t_philosophers *philo)
{
	gettimeofday(&philo->time, NULL);
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

static void	philosophers(
	t_philosophers *philo)
{
	t_philo	*dead;

	dead = NULL;
	while (philo->number_of_times_each_philosopher_must_eat != 0 && !dead)
	{
		philo->number_of_times_each_philosopher_must_eat--;
	}
	if (dead)
		log(dead, DEAD);
}
