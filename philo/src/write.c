/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:41:11 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/15 22:01:55 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_action(
	t_philo *philo,
	char const *action)
{
	if (!thread_is_running(philo) && !ft_strcmp(action, "has died"))
		return ;
	pthread_mutex_lock(&philo->shared_mutexes[MUTEX_WRITE]);
	printf("%u %u %s\n",
		get_current_timestamp_ms() - *philo->timestamp_start,
		philo->id,
		action);
	pthread_mutex_unlock(&philo->shared_mutexes[MUTEX_WRITE]);
}
