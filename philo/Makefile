# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 20:22:21 by sede-san          #+#    #+#              #
#    Updated: 2025/09/25 10:13:30 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

NAME	= philo

# ************************** Compilation variables *************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
HEADERS	= -I $(INCLUDE_PATH)

ifeq ($(DEBUG), lldb)
	CFLAGS += -g3
else ifeq ($(DEBUG), fsanitize-address)
	CFLAGS += -fsanitize=address -g3
else ifeq ($(DEBUG), fsanitize-thread)
	CFLAGS += -fsanitize=thread -g
endif

MAKE += --no-print-directory

# ****************************** Source files ******************************** #

SRC_PATH = src

#! Indicate files before correction
SRC =	$(shell find $(SRC_PATH) -type f -name "*.c")

INCLUDE_PATH = include

# ****************************** Object files ******************************** #

OBJS_PATH = build
OBJS = $(SRC:$(SRC_PATH)/%.c=$(OBJS_PATH)/%.o)

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@$(ECHO) "$< compiled"

# ********************************* Rules ************************************ #

all: $(NAME)
.PHONY: all

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@$(ECHO) "$(GREEN)$(EMOJI_CHECK) $(NAME) ready.$(RESET)"

clean:
	@rm -rf $(OBJS)
	@$(ECHO) "$(RED)$(EMOJI_BROOM) Object files removed.$(RESET)"
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
	@$(ECHO) "$(RED)$(EMOJI_BROOM) Binaries removed.$(RESET)"
.PHONY: fclean

re: fclean all
.PHONY: re

# ********************************* Libraries ******************************** #

LIBS = -lpthread lib/Libft/libft.a #! Libft is here for testing purposes, remove before correction

# ***************************** Style variables ****************************** #

ECHO = echo -e

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
