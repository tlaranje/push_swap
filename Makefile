# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 14:09:52 by tlaranje          #+#    #+#              #
#    Updated: 2025/11/19 10:44:10 by tlaranje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === Executable name ===
NAME		:= push_swap

# === Repositories ===
LIBFT_REPO	:= https://github.com/tlaranje/libft.git

# === Directories ===
SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= inc
LIBFT_DIR	:= libft

# === Commands ===
CC			:= cc
MAKE_C		:= make -C
RM			:= rm -rf
GIT			:= git
FIND		:= find

# === Flags ===
CFLAGS		:= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)

# === Source files ===
MDT_SRC		:= $(shell $(FIND) $(SRC_DIR) -type f -name '*.c')

# === Object files ===
MDT_OBJ		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(MDT_SRC))
LIBFT		:= $(LIBFT_DIR)/libft.a

# === Build targets ===
all: $(OBJ_DIR) libft $(NAME)

# Create obj directory structure matching src/
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Ensure subdirectories exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Link object files into final executable
$(NAME): $(MDT_OBJ) $(LIBFT)
	@$(CC) $(MDT_OBJ) -L$(LIBFT_DIR) -lft -o $@

# Clone libft
clone_libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		$(GIT) clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi

# Build or update libft
libft: clone_libft
	@cd $(LIBFT_DIR) && \
	git fetch origin && \
	if [ $$(git rev-parse HEAD) != $$(git rev-parse @{u}) ]; then \
		echo "Updating libft..."; \
		git pull origin; \
	fi
	@$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE_C) $(LIBFT_DIR) fclean

# Full clean
fclean: clean
	@$(RM) $(NAME) $(LIBFT_DIR)

# Rebuild everything
re: clean all

.PHONY: all clean fclean re libft
