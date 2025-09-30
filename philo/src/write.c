/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:41:11 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/30 14:09:37 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_action(
	t_philo *philo,
	char const *action)
{
	char	*msg;
	char	*timestamp;
	char	*id;

	timestamp = ft_ltoa(get_current_timestamp_ms() - *philo->timestamp_start);
	id = ft_uitoa(philo->id);
	msg = ft_strnjoin(6, timestamp, " ", id, " ", action, "\n");
	pthread_mutex_lock(philo->write_mutex);
	ft_putstr(msg);
	pthread_mutex_unlock(philo->write_mutex);
	free(timestamp);
	free(id);
	free(msg);
}
