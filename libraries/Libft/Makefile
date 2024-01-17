# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 23:10:20 by egiovann          #+#    #+#              #
#    Updated: 2024/01/11 00:04:41 by daddy_cool       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_argument_c.c ft_argument_p.c ft_argument_percent.c ft_argument_s.c ft_argument_u.c ft_arguments_d_i.c ft_arguments_x.c ft_atoi.c ft_bzero.c ft_calloc.c ft_decimal_converter_to_hex.c ft_decimal_lenght.c ft_free_ptr.c get_next_line.c get_next_line_utils.c ft_hex_length.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_print_reversed_str.c ft_printf.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
OBJS := $(SRCS:%.c=%.o)
BSRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstsize.c ft_lstnew.c
BOBJS = $(BSRCS:%.c=%.o)

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)
bonus: $(BOBJS) $(OBJS)
	ar -crs $(NAME) $(OBJS) $(BOBJS)
all: $(NAME)
clean:
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY: bonus all clean fclean re
