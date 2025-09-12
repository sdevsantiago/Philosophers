/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 02:31:36 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 00:40:19 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Converts a string into an integer.  */
int	ft_atoi(
	const char *str)
{
	int	minus;
	int	num;

	minus = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * minus);
}

/* Allocates memory for an array of NMEMB elements of SIZE bytes each.
   Each byte is set to 0.  */
void	*ft_calloc(
	size_t nmemb,
	size_t size)
{
	void	*new_addr;

	new_addr = (void *)malloc(nmemb * size);
	if (!new_addr)
		return (NULL);
	ft_bzero(new_addr, nmemb * size);
	return (new_addr);
}
