/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 03:28:07 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/24 05:17:53 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log(
	t_philo *philosopher,
	t_status status)
{
	if (status == DEAD)
		printf("%ld %d died\n", 0, 0);
	else if (status == FORK)
		printf("%ld %d has taken a fork\n", 0, 0);
	else if (status == EATING)
		printf("%ld %d is eating\n", 0, 0);
	else if (status == SLEEPING)
		printf("%ld %d is sleeping\n", 0, 0);
	else if (status == THINKING)
		printf("%ld %d is thinking\n", 0, 0);
}
