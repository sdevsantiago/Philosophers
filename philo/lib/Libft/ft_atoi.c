/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:37:46 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/24 19:04:21 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Converts a string into an integer.  */
int	ft_atoi(const char *str)
{
	return (ft_atoi_base(str, DEC_BASE));
}
