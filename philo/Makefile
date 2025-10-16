# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 20:22:21 by sede-san          #+#    #+#              #
#    Updated: 2025/10/15 22:31:03 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

NAME	= philo

# ************************** Compilation variables *************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
HEADERS	= -I $(INCLUDE_PATH)

ifeq ($(DEBUG), lldb) # debug with LLDB
	CFLAGS += -g3
else ifeq ($(DEBUG), address) # use AdressSanitize
	CFLAGS += -fsanitize=address -g3
else ifeq ($(DEBUG), thread) # use ThreadSanitize
	CFLAGS += -fsanitize=thread -g3
else # apply optimization flags if no debugging is being done
	CFLAGS += -O3
endif

MAKE += --no-print-directory

# ****************************** Source files ******************************** #

SRC_PATH =		src

SRC =						\
	$(SRC_PATH)/main.c		\
	$(SRC_PATH)/forks.c		\
	$(SRC_PATH)/philos.c	\
	$(SRC_PATH)/routines.c	\
	$(SRC_PATH)/table.c		\
	$(SRC_PATH)/threads.c	\
	$(SRC_PATH)/time.c		\
	$(SRC_PATH)/write.c

SRC_LIBFT_PATH = $(SRC_PATH)/libft

SRC +=									\
	$(SRC_LIBFT_PATH)/ft_atoi_base.c	\
	$(SRC_LIBFT_PATH)/ft_atoi.c			\
	$(SRC_LIBFT_PATH)/ft_atol.c			\
	$(SRC_LIBFT_PATH)/ft_isdigit.c		\
	$(SRC_LIBFT_PATH)/ft_isspace.c		\
	$(SRC_LIBFT_PATH)/ft_strchr.c		\
	$(SRC_LIBFT_PATH)/ft_strcmp.c		\
	$(SRC_LIBFT_PATH)/ft_strisnum.c		\
	$(SRC_LIBFT_PATH)/ft_strlen.c

INCLUDE_PATH =	include

# ****************************** Object files ******************************** #

OBJS_PATH = build
OBJS = $(SRC:$(SRC_PATH)/%.c=$(OBJS_PATH)/%.o)

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@$(PRINTF) "$< compiled"

# ********************************* Rules ************************************ #

all: $(NAME)
.PHONY: all

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@$(PRINTF) "$(GREEN)$(EMOJI_CHECK) $(NAME) ready.$(RESET)"

clean:
	@rm -rf $(OBJS_PATH)
	@$(PRINTF) "$(RED)$(EMOJI_BROOM) Object files removed.$(RESET)"
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
	@$(PRINTF) "$(RED)$(EMOJI_BROOM) Binaries removed.$(RESET)"
.PHONY: fclean

re: fclean all
.PHONY: re

# ********************************* Libraries ******************************** #

LIBS = -lpthread

# ***************************** Style variables ****************************** #

PRINTF =	printf "%b\n"

# Define color codes
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m # No Color

# Emojis
EMOJI_BROOM = 🧹
EMOJI_CHECK = ✅
EMOJI_CROSS = ❌
EMOJI_WRENCH = 🔧
EMOJI_BOX = 📦
