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

BONUS_DIR = ./bonus

BONUS_SRCS	= display_bonus.c ft_putnbr_fd_bonus.c so_long_bonus.c move_bonus.c map_checker_bonus.c\
			insert_sprite_bonus.c init_map_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c animation_monster_bonus.c\
			monster_suite_bonus.c

SRCS	= display.c ft_putnbr_fd.c so_long.c move.c map_checker.c\
			insert_sprite.c init_map.c get_next_line.c get_next_line_utils.c

OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))

OBJSBONUS		= 	$(addprefix $(BONUS_DIR)/, ${BONUS:%.c=%.o})

NAME			=	so_long

BONUS 			=	so_long_bonus

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -g3

RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/

$(BONUS): $(OBJSBONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJSBONUS) minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/

all:		${NAME}
				rm -f $(BONUS)

bonus :		$(BONUS)	
				rm -f $(NAME)

clean:			
	${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean			
		${RM} ${NAME} $(BONUS)

re:			fclean all

.PHONY: 	all clean fclean re
