/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 01:04:36 by sede-san          #+#    #+#             */
/*   Updated: 2025/07/27 03:21:18 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_value(const char c, const char *base);

int	ft_atoi_base(const char *str, const char *base)
{
	int		minus;
	int		num;
	size_t	base_len;

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
	base_len = ft_strlen(base);
	while (*str && ft_strchr(base, *str))
	{
		num = num * base_len + get_value(*str, base);
		str++;
	}
	return (num * minus);
}

static int	get_value(const char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}
