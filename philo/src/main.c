/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:51:58 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/28 19:20:21 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_args(int argc, char const *argv[]);

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

static int	check_args(
	int argc,
	char const *argv[])
{
	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			ft_putendl("Missing arguments");
		else
			ft_putendl("Too many arguments");
		ft_putendl("Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]");
		return (0);
	}
	else if (!*argv[1]
		|| !*argv[2]
		|| !*argv[3]
		|| !*argv[4]
		|| (argv[5] && !*argv[5]))
	{
		
		return (0);
	}
	return (1);
}
