/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:23:45 by sede-san          #+#    #+#             */
/*   Updated: 2025/10/15 22:30:38 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define DEC_BASE "0123456789"

extern int		ft_atoi_base(const char *str, const char *base);

extern int		ft_atoi(const char *str);

extern long		ft_atol(const char *str);

extern int		ft_isdigit(int c);

extern int		ft_isspace(int c);

extern char		*ft_strchr(const char *s, int c);

extern int		ft_strcmp(const char *s1, const char *s2);

extern int		ft_strisnum(const char *str);

extern size_t	ft_strlen(const char *s);

#endif /* LIBFT_H */
