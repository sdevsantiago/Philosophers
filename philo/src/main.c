/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:33:22 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/08 18:01:30 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

typedef struct s_meals_count
{
	pthread_mutex_t	mutex;
	int				count;
}	t_meals_count;

static void	routine_eat(t_meals_count *meals_count);
static void	routine_sleep(t_philo *philo);
static void	routine_think(t_philo *philo);

void	*philo_routine(void *arg)
{
	t_meals_count	*meals_count;

	meals_count = (t_meals_count *)arg;
	while () // check if any philosopher is dead
	{
		routine_eat(meals_count);
		routine_sleep(NULL);
		routine_think(NULL);
	}
	return (NULL); // to be changed
}

static void	routine_eat(t_meals_count *meals_count)
{
	pthread_mutex_lock(&meals_count->mutex);
	meals_count->count--;
	pthread_mutex_unlock(&meals_count->mutex);
	write(1, "eating\n", 7);
}

static void	routine_sleep(t_philo *philo)
{
	(void)philo;
	write(1, "sleeping\n", 9);
}

static void	routine_think(t_philo *philo)
{
	(void)philo;
	write(1, "thinking\n", 9);
}









static int	check_args(int argc, char const *argv[]);
static int	check_meals(t_meals_count *meals_count)
{
	int	ret;

	pthread_mutex_lock(&meals_count->mutex);
	if (!meals_count->count)
		ret = 1;
	else
		ret = 0;
	pthread_mutex_unlock(&meals_count->mutex);
	return (ret);
}

int	main(
	int argc,
	char const *argv[])
{
	if (!check_args(argc, argv))
		return (EXIT_FAILURE);

	pthread_t		thread;
	t_meals_count	meals_count;

	meals_count.count = 100000;
	pthread_mutex_init(&meals_count.mutex, NULL);
	pthread_create(&thread, NULL, philo_routine, &meals_count);
	pthread_join(thread, NULL);

	while (!check_meals(&meals_count)) {}
	pthread_mutex_destroy(&meals_count.mutex);

	return (EXIT_SUCCESS);
}

static int	check_args(
	int argc,
	char const *argv[])
{
	if ((argc < 5 || argc > 6)
		|| !*argv[1] || !*argv[2] || !*argv[3] || !*argv[4]
		|| (argv[5] && !*argv[5]))
		return (printf("ERROR: Missing arguments\n"), 0);
	return (1);
}
