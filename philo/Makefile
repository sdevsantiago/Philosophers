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

#! Indicate files before correction
SRC =			$(shell find $(SRC_PATH) -type f -name "*.c")

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
