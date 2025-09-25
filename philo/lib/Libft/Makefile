# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 19:12:48 by sede-san          #+#    #+#              #
#    Updated: 2025/09/01 19:10:09 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #
# Library name
NAME = libft.a

# Bonus functions relink check file
BONUS_NAME = .bonus

# ************************** Compilation variables *************************** #
# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

DFLAGS = -g3

ifeq ($(DEBUG), 1)
	CFLAGS += $(DFLAGS)
endif

MAKE = make --no-print-directory

# ****************************** Source files ******************************** #
# Mandatory part 1
SRC_MP1= \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c

# Mandatory part 2
SRC_MP2= \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_substr.c

# Bonus part
SRC_B= \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c

# Aditional functions
SRC_A= \
	ft_atoi_base.c \
	ft_atol.c \
	ft_cdlstadd_back.c \
    ft_cdlstadd_front.c \
    ft_cdlstclear.c \
    ft_cdlstdelone.c \
    ft_cdlstiter.c \
    ft_cdlstlast.c \
    ft_cdlstmap.c \
    ft_cdlstnew.c \
    ft_cdlstsize.c \
	ft_clstadd_back.c \
    ft_clstadd_front.c \
    ft_clstclear.c \
    ft_clstdelone.c \
    ft_clstiter.c \
    ft_clstlast.c \
    ft_clstmap.c \
    ft_clstnew.c \
    ft_clstsize.c \
    ft_dlstadd_back.c \
    ft_dlstadd_front.c \
    ft_dlstclear.c \
    ft_dlstdelone.c \
    ft_dlstiter.c \
    ft_dlstlast.c \
    ft_dlstmap.c \
    ft_dlstnew.c \
    ft_dlstsize.c \
	ft_eputchar.c \
	ft_eputendl.c \
	ft_eputstr.c \
	ft_eputnbr.c \
	ft_free.c \
	ft_imin.c \
	ft_free_split.c \
	ft_iscntrl.c \
	ft_islower.c \
	ft_isspace.c \
	ft_itoa_base.c \
	ft_isupper.c \
	ft_ltoa.c \
	ft_putchar.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_realloc.c \
	ft_strisnum.c \
	ft_strncpy.c \
	ft_strnjoin.c \
	ft_swap.c \
	ft_uitoa.c \
	ft_uitoa_base.c \
	ft_ultoa_base.c

# ****************************** Object files ******************************** #z
# Mandatory part 1
OBJ_MP1 = $(SRC_MP1:.c=.o)

# Mandatory part 2
OBJ_MP2 = $(SRC_MP2:.c=.o)

# Bonus part
OBJ_B = $(SRC_B:.c=.o)

# Aditional functions
OBJ_A = $(SRC_A:.c=.o)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ********************************* Rules ************************************ #
# Compile all
all: $(NAME) bonus

$(NAME): $(OBJ_MP1) $(OBJ_MP2) $(OBJ_A)
	ar rcs $(NAME) $(OBJ_MP1) $(OBJ_MP2) $(OBJ_A)

# Compile bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_B)
	ar rcs $(NAME) $(OBJ_B)
	touch $(BONUS_NAME)

# Clean object files
clean:
	rm -f $(OBJ_MP1) $(OBJ_MP2) $(OBJ_B) $(OBJ_A)

# Clean bonus and library
fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f $(OBJ_B)

# Recompile
re: fclean all

# *********************************** Phony ********************************** #
.PHONY = all bonus .bonus clean fclean re
