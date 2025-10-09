/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:53:57 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/09 16:25:32 by sede-san         ###   ########.fr       */
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

typedef unsigned int	t_mseconds;
typedef unsigned int	t_useconds;

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef void			*(*t_routine_func)(void *);

# define INFINITE_MEALS	-1

typedef struct s_table
{
	size_t			philos_count;
	t_philo			*philos;
	pthread_t		waiter;
	t_philo			*dead_philo;
	pthread_mutex_t	*forks;
	t_mseconds		timestamp_start;
	t_mseconds		time_to_die;	// TODO change this three into an array
	t_mseconds		time_to_eat;	// TODO change this three into an array
	t_mseconds		time_to_sleep;	// TODO change this three into an array
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	death_mutex;
}	t_table;

# define LEFT_FORK	0
# define RIGHT_FORK	1

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	pthread_mutex_t	*forks[2];
	t_mseconds		*timestamp_start;
	t_mseconds		timestamp_death;
	t_mseconds		*time_to_die;	// TODO change this three into an array
	t_mseconds		*time_to_eat;	// TODO change this three into an array
	t_mseconds		*time_to_sleep;	// TODO change this three into an array
	long			meals_count;
	pthread_mutex_t	*write_mutex;
	pthread_mutex_t	*death_mutex;
	t_philo			**dead_philo;
}	t_philo;

/******************************************************************************/
/*                                 Functions                                  */
/******************************************************************************/

// forks.c

extern pthread_mutex_t	*forks_init(size_t philos_count);
extern void				forks_clear(pthread_mutex_t *forks, size_t philos_count);
extern void				forks_take(t_philo *philo);
extern void				forks_drop(t_philo *philo);

// philos.c

extern t_philo			*philos_init(t_table *table, long meals_count);
extern void				philos_clear(t_philo *philos);
extern int				philo_eat(t_philo *philo);
extern int				philo_sleep(t_philo *philo);
extern int				philo_think(t_philo *philo);

// routines.c

# define PHILO_DIES		0
# define PHILO_LIVES	1

extern void				*philo_routine(void *arg);
extern int				has_starved(t_philo *philo);

// table.c

extern int				table_init(t_table *table, size_t philos_count, t_mseconds time_to_die, t_mseconds time_to_eat, t_mseconds time_to_sleep, long meals_count);
extern void				table_clear(t_table *table);

// threads.c

extern int				threads_init(t_table *table, t_routine_func routine);

// time.c

extern t_mseconds		get_current_timestamp_ms(void);
extern int				msleep(t_philo *philo, t_mseconds msec);

// write.c

extern void				write_action(t_philo *philo, char const *action);

#endif /* PHILOSOPHERS_H */
