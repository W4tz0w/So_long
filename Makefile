# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 17:28:03 by daddy_cool        #+#    #+#              #
#    Updated: 2024/02/01 02:37:15 by daddy_cool       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_DIR = ./libraries/Libft
MLX_DIR = ./libraries/mlx

LIBS = $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a

SRCS_DIR = ./sources/
BONUS_SRCS_DIR = ./bonus_sources/

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

BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR), \
		so_long_bonus.c			\
		ft_verif_map_bonus.c		\
		ft_quit_game_bonus.c		\
		ft_free_mem_bonus.c	\
		ft_key_hook_bonus.c	\
		ft_init_game_bonus.c		\
		ft_init_map_bonus.c		\
		ft_render_game_bonus.c		\
		ft_utils_bonus_2.c		\
		ft_utils_bonus_1.c)

OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS = -lft -lmlx -framework OpenGL -framework AppKit

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $^
	@echo "\033[0;32mÇa commence déjà bien, $(NAME) compile!\033[0m"

bonus: $(BONUS_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)_bonus $^
	@echo "\033[0;32mBonus, c'est parti youpi-youpla-boum!$(NAME)_bonus compile!\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "\033[0;32m*.o virés, chef!\033[0m"

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NAME)_bonus
	@echo "\033[0;32mC'est bon. $(NAME) est fcleanupé.\033[0m"

re: fclean all

run:			${NAME}
				./${NAME} assets/maps/valid/enzo.ber

runbonus:		${NAME}_bonus
				./${NAME}_bonus assets/maps/valid/bonus/parallel_universe.ber

enemies:		${NAME}_bonus
				./${NAME}_bonus assets/maps/valid/bonus/map-bonus.ber

.PHONY: all clean fclean re
