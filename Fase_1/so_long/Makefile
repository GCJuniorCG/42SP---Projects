# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 13:14:53 by gcamargo          #+#    #+#              #
#    Updated: 2023/01/10 15:14:16 by gcamargo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	clean.c \
				errors.c  \
				events.c \
				init.c \
				main.c \
				map.c \
				map2.c \
				read_map.c \
				read_map2.c \
				sprites.c \
				valid_path.c \
				window.c
				
NAME		=	so_long
CC			=	cc -g3
CFLAGS		=	-Wall -Wextra -Werror

LIBFT		= 	libft.a
IFT			=	-Ilibft -Llibft -lft
MLX			=	/usr/local/include
IMLX		= 	-I minilibx -lXext -lX11 -lmlx -L minilibx

REMOVE		=	rm -rf
LIB			=	libft

OBJSDIR		=	obj
OBJS		= 	$(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

all: 	${NAME}

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@
	
${OBJSDIR}:
	@mkdir -p $@

${LIBFT}: | libft
	@${MAKE} -sC libft/

${OBJS}: | ${LIBFT}

${OBJSDIR}/%.o: src/%.c src/so_long.h Makefile
	@${CC} ${CFLAGS} -c $< -o $@
	
 ${NAME}:	${OBJSDIR}	${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${IFT} ${IMLX} -o $@
	@echo "\033[1;92mSo Long Created\033[0m"

clean:
	@${REMOVE} ${OBJSDIR}
	@${MAKE} clean -C ${LIB}
	@echo "\033[1;93mLib Removed\033[0m"
	
fclean: clean
	@${REMOVE} ${NAME}
	@echo "\033[1;93mSo Long Removed\033[0m"
	
re: fclean all

.PHONY: all clean fclean re

VFLAGS	= --leak-check=full --show-leak-kinds=all --track-fds=yes -s -q \
--log-file=valErrors
v: $(OBJ)
	$(CC) -g3 $(CFLAGS) $(OBJS) libft/$(LIBFT) $(IMLX) -o $@
	clear
	@valgrind $(VFLAGS) ./$@ maps/map.ber
	@rm -f $@