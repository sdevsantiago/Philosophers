# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 20:22:21 by sede-san          #+#    #+#              #
#    Updated: 2025/08/24 02:46:00 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

# Executable file name
NAME = philo

# ************************** Compilation variables *************************** #

# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code # -Ofast

# Additional headers
HEADERS = -I $(INCLUDE_PATH) # -I $(GNL_INCLUDE_PATH) -I $(PRINTF_INCLUDE_PATH) -I $(LIBFT_INCLUDE_PATH)

# Debug flags, execute with DEBUG=1 -> make DEBUG=1
DFLAGS = -g3
ifeq ($(DEBUG), 1)
	CFLAGS += $(DFLAGS)
endif

# Make command with no-print-directory flag
MAKE += --no-print-directory

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

# ****************************** Source files ******************************** #

# Source files path
SRC_PATH = src

# Source files
SRC = \
	$(SRC_PATH)/philo.c \
	$(SRC_PATH)/utils/ctype_utils.c \
	$(SRC_PATH)/utils/stdlib_utils.c \
	$(SRC_PATH)/utils/time_utils.c

# Include path
INCLUDE_PATH = ./include

# ****************************** Object files ******************************** #

# Object files path
OBJS_PATH = build

# Source files and destination paths
OBJS = $(SRC:$(SRC_PATH)/%.c=$(OBJS_PATH)/%.o)

# Compile as object files
$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "$< compiled"

# ********************************* Rules ************************************ #

# Compile all
all: $(NAME)
.PHONY: all

# Compile project
$(NAME): $(OBJS)
	@echo "$(YELLOW)$(EMOJI_BOX) Linking...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(EMOJI_CHECK) Linked.$(RESET)"

# Clean object files
clean:
	@echo "$(RED)$(EMOJI_BROOM) Cleaning object files...$(RESET)"
	@rm -rf $(OBJS_PATH)
	@echo "$(GREEN)$(EMOJI_CHECK) Object files cleaned.$(RESET)"
.PHONY: clean

# Clean object files and binaries
fclean: clean
	@echo "$(RED)$(EMOJI_BROOM) Cleaning binaries...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(EMOJI_CHECK) Binaries cleaned.$(RESET)"
.PHONY: fclean

# Recompile
re: fclean all
.PHONY: re

# ********************************* Libraries ******************************** #

# Libraries path
LIB_PATH = -lpthread
