# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opodolia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 16:00:27 by opodolia          #+#    #+#              #
#    Updated: 2017/03/22 16:43:40 by opodolia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_BASE = fdf

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# directories
FDF_SRC_DIR = ./src/
FDF_OBJ_DIR = ./obj/
FDF_INC_DIR = ./includes/

# fdf source files
FDF_FILES = main.c validate_map.c depth_colors.c image.c \
			rendering.c line.c mouse_keyboard.c \

FDF_OBJ = $(addprefix $(FDF_OBJ_DIR), $(FDF_FILES:.c=.o))

# libftprintf
LIB_DIR = ./libft_printf/
LIB = $(addprefix $(LIB_DIR), libftprintf.a)
LIB_INC = -I ./libft_printf
LIB_LNK = -L ./libft_printf -l ftprintf

# mlx lib
MLX_DIR = ./minilibx/
MLX_LIB = $(addprefix $(MLX_DIR), mlx.a)
MLX_INC = -I ./minilibx
MLX_LNK = -L ./minilibx -l mlx -framework OpenGL -framework AppKit

.SILENT:

all: $(LIB) $(MLX_LIB) $(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAME_BASE) is done\033[0m\033[K"

$(FDF_OBJ_DIR)%.o: $(FDF_SRC_DIR)%.c
	printf "\r\033[38;5;11m⌛  MAKE $(NAME_BASE) please wait ...\033[0m\033[K"
	mkdir -p $(FDF_OBJ_DIR)
	$(CC) $(CFLAGS) $(MLX_INC) $(LIB_INC) -I $(FDF_INC_DIR) -o $@ -c $<

$(LIB):
	make -C $(LIB_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(FDF_OBJ)
	$(CC) $(FDF_OBJ) $(MLX_LNK) $(LIB_LNK) -lm -o $(NAME)
	echo -en "\r\033[38;5;22m☑️  MAKE $(NAME_BASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat author | sed s/^/\ \ \ \ /g`\033[0m\033[K"

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAME_BASE) please wait ...\033[0m\033[K"
	rm -rf $(FDF_OBJ_DIR)
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	printf "\r\033[38;5;11m☑️  CLEAN  $(NAME_BASE) is done\033[0m\033[K"

fclean: clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAME_BASE) please wait ...\033[0m\033[K"
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean
	printf "\r\033[38;5;11m☑️  FCLEAN  $(NAME_BASE) is done\033[0m\033[K"

re: fclean all

.PHONY: fclean clean re
