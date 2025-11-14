# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 10:52:34 by tlaranje          #+#    #+#              #
#    Updated: 2025/11/14 13:10:42 by tlaranje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === Executable name ===
NAME			:= push_swap

# === Repositories ===
LIBFT_REPO		:= https://github.com/tlaranje/libft.git

# === Directories ===
SRC_DIR			:= src
OBJ_DIR			:= obj
INC_DIR			:= inc
LIBFT_DIR		:= libft

# === Commands ===
CC				:= cc
MAKE_C			:= make -C
RM				:= rm -rf

# === Flags ===
CFLAGS			:= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)

# === Source files ===
MDT_SRC			:= $(wildcard $(SRC_DIR)/*.c)

# === Object files ===
MDT_OBJ			:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(MDT_SRC)))
LIBFT			:= $(LIBFT_DIR)/libft.a

# === Build targets ===
all: $(OBJ_DIR) libft $(NAME)

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into final executable
$(NAME): $(MDT_OBJ) $(LIBFT)
	$(CC) $(MDT_OBJ) -L$(LIBFT_DIR) -lft -o $@

# Build libft
libft:
	if [ ! -d "$(LIBFT_DIR)" ]; then git clone $(LIBFT_REPO) $(LIBFT_DIR); fi
	$(MAKE_C) $(LIBFT_DIR)

# Remove object files
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE_C) $(LIBFT_DIR) clean

# Remove executables and object files
fclean: clean
	$(RM) $(NAME) $(LIBFT_DIR)

# Rebuild everything
re: fclean all

.PHONY: all bonus clean fclean re libft