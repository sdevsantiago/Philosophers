/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 02:45:23 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/24 03:30:22 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Checks if the character is a white-space.  */
int	ft_isspace(
	int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}
