/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 03:00:12 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/01 00:15:46 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i])
	{
		ft_bzero(splitted[i], ft_strlen(splitted[i]));
		free(splitted[i]);
		i++;
	}
	ft_bzero(splitted, (i + 1) * sizeof(char *));
	free(splitted);
}
