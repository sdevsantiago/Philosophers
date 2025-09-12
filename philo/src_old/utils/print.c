/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 03:28:07 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 18:25:51 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(char const *msg, t_philo *philo)
{

}
void	log_status(
	t_philo *p)
{
	if (p->status == DEAD)
		printf("%d %d died\n", 0, 0);
	else if (p->status == FORK)
		printf("%d %d has taken a fork\n", 0, 0);
	else if (p->status == EATING)
		printf("%d %d is eating\n", 0, 0);
	else if (p->status == SLEEPING)
		printf("%d %d is sleeping\n", 0, 0);
	else if (p->status == THINKING)
		printf("%d %d is thinking\n", 0, 0);
}

void	print_error(
	char const *msg)
{
	printf("ERROR: %s\n", msg);
}
