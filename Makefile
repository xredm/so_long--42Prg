# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 12:01:59 by mredkole          #+#    #+#              #
#    Updated: 2023/09/30 19:51:09 by mredkole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long
SRCS =	so_long.c so_long_utils.c map.c map_utils.c utils.c sprites.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: lib $(NAME)

lib:
	make -C libft all bonus
	make -C minilibx-linux

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) minilibx-linux/libmlx.a libft/libft.a -lXext -lX11

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@	

clean:
	rm -rf $(OBJS)
	make fclean -C libft
	make clean -C minilibx-linux

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re