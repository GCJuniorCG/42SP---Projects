# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 19:37:43 by gcamargo          #+#    #+#              #
#    Updated: 2023/01/08 23:41:28 by gcamargo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= clang
CFLAGS	= -Wall -Werror -Wextra
INC		= -I. -I..

LIB		= ../libft.a
REMOVE	= rm -rf
SRCS	= \
	ft_printf.c \
	ft_printf_utils.c \
	dot_disp.c \
	dot_wr.c \
	dot.c \
	minus_disp.c \
	minus_wr.c \
	minus.c \
	space_disp.c \
	space_wr.c \
	space.c \
	zero_disp.c \
	zero_wr.c \
	zero.c \
	sharp.c \
	plus.c

OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

${NAME}: | ${LIB} ${OBJSDIR} ${OBJS}
	ar -rcs $@ $^

${LIB}:
	${MAKE} -C libft/

${OBJSDIR}:
	mkdir -p $@

${OBJSDIR}/%.o: %.c
	${CC} ${CFLAGS} ${INC} -c $< -o $@

bonus: all

clean:
	@$(REMOVE) ${OBJSDIR}

fclean: clean
	@$(REMOVE) ${NAME}

re: fclean all

.PHONY	: all clean fclean re bonus