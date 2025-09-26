/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:51:58 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/26 20:22:41 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(
	int argc,
	char const *argv[])
{
	(void)argc;
	(void)argv;

	t_table	table;

	if (!init_table(&table))
	{
		write(STDERR_FILENO, "failed to initialize table\n", 27);
		return (EXIT_FAILURE);
	}
	if (!init_threads(&table, philo_routine))
	{
		write(STDERR_FILENO, "failed to run threads\n", 22);
		return (EXIT_FAILURE);
	}
	//? maybe main function has to check if philosophers are either still alive or have finished eating
	clear_table(&table);
	return (EXIT_SUCCESS);
}
