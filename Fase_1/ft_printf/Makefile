# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 22:04:09 by gcamargo          #+#    #+#              #
#    Updated: 2022/07/26 22:19:42 by gcamargo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_format.c ft_printf_format_hex.c

LIBFT_COMPILE = cd libft && make

LIBFT_COPY = cp ./libft/libft.a $(NAME)

LIBFT_FCLEAN = cd libft && make fclean

HEADER = ft_printf.h

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

.c.o:
	cc $(CCFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(HEADER)
	$(LIBFT_COMPILE)
	$(LIBFT_COPY)
	$(LIBFT_FCLEAN)
	ar -rcs $(NAME) $(OBJ) $(HEADER)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean 
