/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:51:58 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/17 19:59:38 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_args(int argc, char const *argv[]);

int	main(
	int argc,
	char const *argv[])
{
	t_table	table;

	if (!check_args(argc, argv))
		return (EXIT_FAILURE);
	if (!table_init(&table, argv))
	{
		printf("Error: %s\n", "failed to initialize table");
		return (EXIT_FAILURE);
	}
	if (!threads_run(&table, philo_routine, waiter_routine))
	{
		printf("Error: %s\n", "failed to run threads");
		return (EXIT_FAILURE);
	}
	table_clear(&table);
	return (EXIT_SUCCESS);
}

static int	check_values(int argc, char const *argv[]);

static int	check_args(
	int argc,
	char const *argv[])
{
	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			printf("Invalid usage: %s\n", "missing arguments");
		else
			printf("Invalid usage: %s\n", "too many arguments");
		printf("Usage: ./%s %s %s %s %s %s\n", "philo",
			"<number_of_philosophers>", "<time_to_die>", "<time_to_eat>",
			"<time_to_sleep>", "[number_of_times_each_philosopher_must_eat]");
		return (0);
	}
	return (check_values(argc, argv));
}

static int	check_values(int argc, char const *argv[])
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i] && !*argv[i])
		{
			printf("Invalid usage: %s\n", "empty arguments");
			return (0);
		}
		else if (!ft_strisnum(argv[i])
			|| ft_strchr(argv[i], '-')
			|| ((i == 0 || i == 5) && ft_atol(argv[i]) <= 0)
			|| ((i > 0 && i < 5) && ft_atoi(argv[i]) <= 0))
		{
			printf("Invalid usage: %s\n",
				"arguments can't be negative or zero");
			return (0);
		}
	}
	return (1);
}
