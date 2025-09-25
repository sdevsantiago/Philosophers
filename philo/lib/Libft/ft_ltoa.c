/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 00:54:33 by sede-san          #+#    #+#             */
/*   Updated: 2025/07/10 01:05:55 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of digits in the integer N.  */
static size_t	count_digits(long n)
{
	size_t	digits;

	digits = 0;
	if (n == LONG_MIN)
		return (10);
	else if (n == 0)
		return (1);
	else if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

/* Converts an long into a string.  */
char	*ft_ltoa(long n)
{
	char	*num_str;
	size_t	digits;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	digits = count_digits(n);
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	num_str = (char *)malloc((digits + 1) * sizeof(*num_str));
	if (!num_str)
		return (NULL);
	num_str[digits] = '\0';
	while (digits-- > 0)
	{
		num_str[digits] = (n % 10) + '0';
		n /= 10;
	}
	if (num_str[0] == '0' && num_str[1] != '\0')
		num_str[0] = '-';
	return (num_str);
}
