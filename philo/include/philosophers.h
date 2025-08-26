/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:10:54 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/24 05:17:53 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_status
{
	FORK,
	EATING,
	THINKING,
	SLEEPING,
	DEAD
}	t_status;

typedef struct s_philo
{
	unsigned int	id;
	t_status		status;
}	t_philo;

typedef struct s_philosophers
{
	struct timeval	time;
	t_philo	*philosophers;
	unsigned int	number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	number_of_times_each_philosopher_must_eat;
}	t_philosophers;

/* ********************************* Utils ********************************** */

// ctype_utils.c

int		ft_isspace(int c);

// log.c

void	log(t_philo *philosopher, int status);

// stdlib_utils.c

int		ft_atoi(const char *str);

// time_utils.c

long	time_to_ms(struct timeval *time);

#endif /* PHILOSOPHERS_H */
