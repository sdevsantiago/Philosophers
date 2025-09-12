/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:54:15 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 18:09:18 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_args(char const *argv[]);

int	main(
	int argc,
	char const *argv[])
{
	t_philosophers	philosophers;

	if (!check_args)
		return (print_error("Invalid usage"), EXIT_FAILURE);
	init_philosophers(argv, &philosophers);
	if (!philosophers.philos)
		return (print_error("Out of memory"), EXIT_FAILURE);
	run_philosophers(&philosophers);
	clear_philosophers(&philosophers);
	return (EXIT_SUCCESS);
}

static int	check_args(char const *argv[])
{

}
