# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xredm <xredm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 18:43:53 by mredkole          #+#    #+#              #
#    Updated: 2023/05/15 21:31:12 by xredm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c\
	ft_itoa.c ft_memchr.c ft_memcmp.c\
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c\
	ft_printf.c ft_printf_basic.c
SRCSB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
	ft_lstmap.c

OBJS = ${SRCS:.c=.o}

OBJSB = ${SRCSB:.c=.o}

NAME = libft.a

HDR := libft.h

CFLAGS := -Wall -Wextra -Werror

CC := cc

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus: ${NAME} ${OBJSB}
	@ar rc ${NAME} ${OBJSB}

clean:
	@rm -f ${OBJS} ${OBJSB} 

fclean: clean
	@rm -f ${NAME} ${bonus} 

re: fclean all

.PHONY : all bonus clean fclean re
