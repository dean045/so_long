# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 14:49:32 by abahmani          #+#    #+#              #
#    Updated: 2022/02/11 15:48:43 by brhajji-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs

SRCS	= display.c ft_putnbr_fd.c so_long.c move.c map_checker.c\
			insert_sprite.c init_map.c get_next_line.c get_next_line_utils.c animation_monster.c\
			monster_suite.c

OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))

OBJSBONUS		= 	${BONUS:.c=.o}

NAME			=	so_long

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -g3

RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/

all:		${NAME}

clean:			
	${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean			
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
