# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 20:22:21 by sede-san          #+#    #+#              #
#    Updated: 2025/09/08 17:25:17 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

NAME	= philo

# ************************** Compilation variables *************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
HEADERS	= -I $(INCLUDE_PATH)

ifeq ($(DEBUG), 1)
	CFLAGS += -g3 -Og
endif

MAKE += --no-print-directory

# ****************************** Source files ******************************** #

SRC_PATH = src

SRC =							\
		$(SRC_PATH)/main.c		\
# 		$(SRC_PATH)/routines.c	\

INCLUDE_PATH = include

# ****************************** Object files ******************************** #

OBJS_PATH = build
OBJS = $(SRC:$(SRC_PATH)/%.c=$(OBJS_PATH)/%.o)

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$< compiled"

# ********************************* Rules ************************************ #

all: $(NAME)
.PHONY: all

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(EMOJI_CHECK) $(NAME) ready.$(RESET)"

clean:
	@rm -rf $(OBJS)
	@echo "$(RED)$(EMOJI_BROOM) Object files removed.$(RESET)"
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(EMOJI_BROOM) Binaries removed.$(RESET)"
.PHONY: fclean

re: fclean all
.PHONY: re

# ********************************* Libraries ******************************** #

LIBS = -lpthread

# ***************************** Style variables ****************************** #

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
