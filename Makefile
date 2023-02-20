# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 09:52:47 by dcologgi          #+#    #+#              #
#    Updated: 2023/02/20 11:26:41 by dcologgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJS}
		${CC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

