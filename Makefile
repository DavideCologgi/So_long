# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 09:52:47 by dcologgi          #+#    #+#              #
#    Updated: 2023/03/01 13:03:38 by dcologgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = get_map.c close_game.c keypressed.c get_next_line.c \
get_next_line_utils.c main.c map_gen.c errors.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iheaders
LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX = minilibx

%.o: %.c
		${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJS}
		make -C ${MINILIBX}
		${CC} ${OBJS} ${LIBRARY} -o ${NAME}

all:
		make -C ${MINILIBX}
		${CC} ${CFLAGS} ${SRCS} ${LIBRARY} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		make clean -C ${MINILIBX}
		${RM} ${NAME}

re: fclean all

