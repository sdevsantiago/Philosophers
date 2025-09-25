/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 00:15:46 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 19:04:43 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Joins multiple strings into a single newly allocated string.
 *
 * This function concatenates a variable number of strings, specified by the
 * 'count' parameter, into a single string. The resulting string is dynamically
 * allocated and must be freed by the caller. If any input string is NULL or
 * memory allocation fails, the function returns NULL.
 *
 * @param count The number of strings to join.
 * @param ...   The strings to be joined (each of type 'char *').
 *
 * @return A pointer to the newly allocated concatenated string, or NULL on
 *         error.
 *
 * @note The function expects at least one string. If 'count' is less than or
 *       equal to 0, the function returns NULL.
 * @note The returned string must be freed later to avoid leaks.
 */
char	*ft_strnjoin(int count, ...)
{
	va_list	args;
	char	*result;
	char	*temp;
	char	*current_str;

	if (count <= 0)
		return (NULL);
	va_start(args, count);
	result = ft_strdup(va_arg(args, char *));
	if (!result)
		return (va_end(args), NULL);
	while (--count)
	{
		current_str = va_arg(args, char *);
		if (!current_str)
			return (free(result), va_end(args), NULL);
		temp = ft_strjoin(result, current_str);
		free(result);
		if (!temp)
			return (va_end(args), NULL);
		result = temp;
	}
	va_end(args);
	return (result);
}
