/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:51:58 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/30 09:48:28 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_args(int argc, char const *argv[]);

int	main(
	int argc,
	char const *argv[])
{
	t_table	table;
	long	meals_count;

	if (!check_args(argc, argv))
		return (EXIT_FAILURE);
	if (argv[5])
		meals_count = ft_atol(argv[5]);
	else
		meals_count = -1;
	if (!init_table(&table,
			(size_t)ft_atol(argv[1]),
			(t_mseconds)ft_atoi(argv[2]),
			(t_mseconds)ft_atoi(argv[3]),
			(t_mseconds)ft_atoi(argv[4]),
			meals_count))
	{
		write(STDERR_FILENO, "failed to initialize table\n", 27);
		return (EXIT_FAILURE);
	}
	if (!init_threads(&table, philo_routine))
	{
		write(STDERR_FILENO, "failed to run threads\n", 22);
		return (EXIT_FAILURE);
	}
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
	else if (!*argv[1] || !*argv[2] || !*argv[3] || !*argv[4]
		|| (argv[5] && !*argv[5]))
	{
		ft_putendl("Missing arguments");
		return (0);
	}
	else if ((!ft_strisnum(argv[1]) || ft_strchr(argv[1], '-') || ft_atol(argv[1]) < 1)
		|| (!ft_strisnum(argv[2]) || ft_strchr(argv[2], '-') || ft_atoi(argv[2]) < 1)
		|| (!ft_strisnum(argv[3]) || ft_strchr(argv[3], '-') || ft_atoi(argv[3]) < 1)
		|| (!ft_strisnum(argv[4]) || ft_strchr(argv[4], '-') || ft_atoi(argv[4]) < 1)
		|| (argv[5] && (!ft_strisnum(argv[5]) || ft_strchr(argv[5], '-') || ft_atol(argv[5]) < 1)))
	{
		ft_putendl("Arguments can't be negative or zero");
		return (0);
	}
	return (1);
}
