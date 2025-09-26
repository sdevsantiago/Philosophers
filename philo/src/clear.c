/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:52:21 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/26 01:59:27 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clear_forks(
	size_t philos_count,
	pthread_mutex_t *forks)
{
	while (--philos_count)
		pthread_mutex_destroy(&forks[philos_count]);
	free(forks);
}
