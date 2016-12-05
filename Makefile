# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: behamon <behamon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 12:33:09 by behamon           #+#    #+#              #
#    Updated: 2016/12/05 19:08:04 by behamon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fdf

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
MLX_FLAGS = -framework OpenGL -framework AppKit -lmlx

LFT_PATH = ./libft/
MLX_PATH = ./mlx/

SRC = parse_map.c draw_fdf.c utilities_fdf.c hud.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@make -C $(MLX_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) $(MLX_FLAGS) -L$(LFT_PATH) -lft
	@echo "$(OKC)FDF:\t\tCompilation.. \tPrêt$(NOC)"

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)FDF:\t\tSuppression du dossier objet :\t./obj/$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)FDF:\t\tSuppression de l'executable  :\tfdf$(NOC)"

re: fclean all
