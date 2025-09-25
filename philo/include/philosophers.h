/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:53:57 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/25 10:04:51 by sede-san         ###   ########.fr       */
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
# include <strings.h>
# include <time.h>		// gettimeofday()
# include <unistd.h>	// write(), usleep()

/******************************************************************************/
/*                                 Structures                                 */
/******************************************************************************/

typedef struct s_philo	t_philo;

typedef struct s_philosophers
{
	/* data */
}	t_philosophers;

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_mutex;
}	t_philo;

/******************************************************************************/
/*                                 Functions                                  */
/******************************************************************************/

// routines.c

void	*philo_routine(void *arg);

#endif /* PHILOSOPHERS_H */
