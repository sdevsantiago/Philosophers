/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:10:54 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/08 16:44:11 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>	// threads and mutexes
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>	// write()
# include <errno.h>

typedef enum e_status
{
	FORK,
	EATING,
	THINKING,
	SLEEPING,
	DEAD
}	t_status;

/**
 * @brief Represents a philosopher in the dining philosophers problem
 *
 * This structure contains all the necessary data for a philosopher thread,
 * including their unique identifier, current status, thread handle, and
 * the mutexes representing the forks they need to eat.
 *
 * @param id            Unique identifier for the philosopher (starting from 1)
 * @param status        Current status of the philosopher (eating, thinking,
 *                      sleeping, etc.)
 * @param thread        The pthread handle for this philosopher's thread
 * @param fork_left     Mutex representing the philosopher's own fork
 * @param fork_right    Pointer to the next philosopher's fork mutex
 * @param time_to_die   Maximum time (ms) a philosopher can survive without
 *                      eating
 * @param time_to_eat   Duration (ms) required for a philosopher to complete
 *                      eating
 * @param time_to_sleep Duration (ms) a philosopher spends sleeping
 */
typedef struct s_philo
{
	unsigned int	id;
	t_status		status;
	pthread_t		thread;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	*fork_right;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	meals_count;
}	t_philo;

/**
 * @brief Main structure containing simulation parameters and philosopher data
 *
 * This structure holds all the configuration parameters for the dining philosophers
 * simulation, including timing constraints, philosopher count, and references to
 * the philosopher entities.
 *
 * @param time              Reference time for the simulation start
 * @param philos            Pointer to array of philosopher structures
 * @param philosopher_count Total count of philosophers in the simulation
 * @param meals_count       Minimum meals required per philosopher (optional)
 */
typedef struct s_philosophers
{
	struct timeval	time;
	t_philo			*philos;
	unsigned int				philosopher_count;
}	t_philosophers;

// routines.c

void	*philo_routine(void *arg);

// conversion_utils.c

int		ft_atoi(const char *str);
long	ft_atol(const char *str);

// type_utils.c

int		ft_strisnum(const char *str);

#endif /* PHILO_H */
