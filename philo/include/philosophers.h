/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:53:57 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/15 19:56:52 by sede-san         ###   ########.fr       */
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

# define TIME_DIE	0
# define TIME_EAT	1
# define TIME_SLEEP	2

# define MUTEX_WRITE	0
# define MUTEX_STOP	1

typedef struct s_table
{
	size_t			philos_count;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		waiter;
	t_mseconds		timestamp_start;
	t_mseconds		time_to[3];
	pthread_mutex_t	shared_mutexes[2];
	int				stop;
}	t_table;

# define FORK_LEFT	0
# define FORK_RIGHT	1

# define INFINITE_MEALS	-1

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	pthread_mutex_t	*forks[2];
	long			meals_count;
	t_mseconds		*timestamp_start;
	t_mseconds		timestamp_death;
	t_mseconds		*time_to;
	pthread_mutex_t	*shared_mutexes;
	int				*stop;
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
extern void				philo_eat(t_philo *philo);
extern void				philo_sleep(t_philo *philo);
extern void				philo_think(t_philo *philo);

// routines.c

# define PHILO_DIES		0
# define PHILO_LIVES	1

extern void				*philo_routine(void *arg);
extern void				*waiter_routine(void *arg);
extern int				philo_has_starved(t_philo *philo);

// table.c

extern int				table_init(t_table *table, size_t philos_count, t_mseconds time_to_die, t_mseconds time_to_eat, t_mseconds time_to_sleep, long meals_count);
extern void				table_clear(t_table *table);

// threads.c

extern int				threads_run(t_table *table, t_routine_func philo_routine, t_routine_func waiter_routine);
extern void				threads_stop(t_table *table);
extern int				thread_is_running(t_philo *philo);

// time.c

extern t_mseconds		get_current_timestamp_ms(void);
extern int				msleep(t_philo *philo, t_mseconds msec);

// write.c

extern void				write_action(t_philo *philo, char const *action);

#endif /* PHILOSOPHERS_H */
