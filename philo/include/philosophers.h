/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:53:57 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/28 19:27:27 by sede-san         ###   ########.fr       */
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
# include <unistd.h>	// write(), usleep()


/******************************************************************************/
/*                           Structures & Data Types                          */
/******************************************************************************/

typedef unsigned int t_mseconds;

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef void *(*t_routine_func)(void *);

typedef struct s_table
{
	size_t			philos_count;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_mseconds		timestamp_start;
	t_mseconds		time_to_die;	// TODO change this three into an array
	t_mseconds		time_to_eat;	// TODO change this three into an array
	t_mseconds		time_to_sleep;	// TODO change this three into an array
	pthread_mutex_t	write_mutex;
}	t_table;

# define LEFT_FORK 0
# define RIGHT_FORK 1

typedef struct s_philo
{
	unsigned long	id;
	pthread_t		thread;
	pthread_mutex_t	*forks[2];
	t_mseconds		*timestamp_start;
	t_mseconds		timestamp_death;
	t_mseconds		*time_to_die;	// TODO change this three into an array
	t_mseconds		*time_to_eat;	// TODO change this three into an array
	t_mseconds		*time_to_sleep;	// TODO change this three into an array
	long			meals_count;
	pthread_mutex_t	*write_mutex;
}	t_philo;


/******************************************************************************/
/*                                 Functions                                  */
/******************************************************************************/

// forks.c

pthread_mutex_t	*init_forks(size_t philos_count);
void			clear_forks(pthread_mutex_t *forks, size_t philos_count);

// philos.c

t_philo			*init_philos(t_table *table, long meals_count);
void			clear_philos(t_philo *philos);

// routines.c

void			*philo_routine(void *arg);

// table.c

int				init_table(t_table *table);
void			clear_table(t_table *table);

// threads.c

int				init_threads(t_table *table, t_routine_func routine);

// time.c

t_mseconds		get_current_timestamp_ms(void);
int				msleep(t_mseconds msec);

#endif /* PHILOSOPHERS_H */
