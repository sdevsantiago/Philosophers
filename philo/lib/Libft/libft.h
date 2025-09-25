/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:40:58 by sede-san          #+#    #+#             */
/*   Updated: 2025/09/01 19:10:41 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# ifdef __unix__
#  include <linux/limits.h>
# endif
# include <unistd.h>
# include "colors.h"

/* **************************** Part 1 functions **************************** */

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);

/* **************************** Part 2 functions **************************** */

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_itoa(int n);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		**ft_split(const char *s, char c);

/* ***************************** Bonus functions **************************** */

// Single linked list structure
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
int			ft_lstsize(t_list *lst);

/* *************************** Aditional functions ************************** */

# define BIN_BASE "01"
# define OCT_BASE "01234567"
# define DEC_BASE "0123456789"
# define HEX_BASE "0123456789ABCDEF"

void		ft_eputchar(char c);
void		ft_eputendl(char *s);
void		ft_eputstr(char *s);
void		ft_eputnbr(int n);
void		ft_free(void **ptr);
void		ft_free_split(char **splitted);
void		ft_putchar(char c);
void		ft_putendl(char *s);
void		ft_putnbr(int n);
void		ft_putstr(char *s);
void		ft_swap(void *a, void *b);
void		*ft_realloc(void *ptr, size_t size);
int			ft_atoi_base(const char *str, const char *base);
int			ft_imin(int a, int b);
int			ft_iscntrl(int c);
int			ft_islower(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);
int			ft_strisnum(const char *str);
long		ft_atol(const char *str);
char		*ft_itoa_base(int n, const char *base);
char		*ft_ltoa(long n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strnjoin(int count, ...);
char		*ft_uitoa(unsigned int n);
char		*ft_uitoa_base(unsigned int n, const char *base);
char		*ft_ultoa_base(unsigned long n, const char *base);

// Doubly linked list
typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}					t_dlist;

t_dlist		*ft_dlstlast(t_dlist *lst);
t_dlist		*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *));
t_dlist		*ft_dlstnew(void *content);
void		ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void		ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void		ft_dlstclear(t_dlist **lst, void (*del)(void *));
void		ft_dlstdelone(t_dlist *dst, void (*del)(void *));
void		ft_dlstiter(t_dlist *lst, void (*f)(void *));
int			ft_dlstsize(t_dlist *lst);

// Circular single linked list structure
typedef struct s_clist
{
	void			*content;
	struct s_clist	*next;
}					t_clist;

t_clist		*ft_clstlast(t_clist *lst);
t_clist		*ft_clstmap(t_clist *lst, void *(*f)(void *), void (*del)(void *));
t_clist		*ft_clstnew(void *content);
void		ft_clstadd_back(t_clist **lst, t_clist *new);
void		ft_clstadd_front(t_clist **lst, t_clist *new);
void		ft_clstclear(t_clist **lst, void (*del)(void *));
void		ft_clstdelone(t_clist *lst, void (*del)(void *));
void		ft_clstiter(t_clist *lst, void (*f)(void *));
int			ft_clstsize(t_clist *lst);

// Circular doubly linked list structure
typedef struct s_cdlist
{
	void			*content;
	struct s_cdlist	*next;
	struct s_cdlist	*previous;
}					t_cdlist;

t_cdlist	*ft_cdlstlast(t_cdlist *lst);
t_cdlist	*ft_cdlstmap(t_cdlist *lst, void *(*f)(void *),
				void (*del)(void *));
t_cdlist	*ft_cdlstnew(void *content);
void		ft_cdlstadd_back(t_cdlist **lst, t_cdlist *new);
void		ft_cdlstadd_front(t_cdlist **lst, t_cdlist *new);
void		ft_cdlstclear(t_cdlist **lst, void (*del)(void *));
void		ft_cdlstdelone(t_cdlist *lst, void (*del)(void *));
void		ft_cdlstiter(t_cdlist *lst, void (*f)(void *));
int			ft_cdlstsize(t_cdlist *lst);

#endif
