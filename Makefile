# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 17:28:03 by daddy_cool        #+#    #+#              #
#    Updated: 2024/01/17 17:28:05 by daddy_cool       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_DIR = ./libraries/Libft
MLX_DIR = ./libraries/mlx

LIBS = $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a

SRCS_DIR = ./sources/

SRCS = $(addprefix $(SRCS_DIR), \
		so_long.c			\
		ft_verif_map.c		\
		ft_quit_game.c		\
		ft_free_mem.c	\
		ft_key_hook.c	\
		ft_init_game.c		\
		ft_init_map.c		\
		ft_render_game.c		\
		ft_utils.c)

OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS = -lft -lmlx -framework OpenGL -framework AppKit

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $^
	@echo "\033[0;32m$(NAME) compiled successfully!\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)
	@echo "\033[0;32mCleaned up object files!\033[0m"

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	@echo "\033[0;32mCleaned up $(NAME)!\033[0m"

re: fclean all

run:			${NAME}
				./${NAME} assets/maps/valid/map2.ber

.PHONY: all clean fclean re
