/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:53:57 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/26 02:18:02 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//! only for testing
# include "../lib/Libft/libft.h"

# include <pthread.h>	// threads and mutexes
# include <stdio.h>		// printf()
# include <stdlib.h>	// malloc(), free()
# include <string.h>	// memset()
# include <sys/time.h>	// gettimeofday()
# include <time.h>		// gettimeofday()
# include <unistd.h>	// write(), usleep()

/******************************************************************************/
/*                                 Structures                                 */
/******************************************************************************/

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_table
{
	size_t			philos_count;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	pthread_mutex_t	write_mutex;
}	t_table;

typedef struct s_philo
{
	unsigned long	id;
	pthread_t		thread;
	pthread_mutex_t	*forks[2];
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	long			meals_count;
	pthread_mutex_t	*write_mutex;
}	t_philo;

# define LEFT_FORK 0
# define RIGHT_FORK 1

/******************************************************************************/
/*                                 Functions                                  */
/******************************************************************************/

// clear.c

void	clear_forks(size_t philos_count, pthread_mutex_t *forks);

// init.c

typedef void *(*t_routine_func)(void *);

int		init_table(t_table *table);
int		init_threads(t_table *table, t_routine_func routine);

// routines.c

void	*philo_routine(void *arg);

// time.c

long	get_current_time_ms(void);

#endif /* PHILOSOPHERS_H */
