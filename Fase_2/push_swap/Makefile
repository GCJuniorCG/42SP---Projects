# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:48:54 by gcamargo          #+#    #+#              #
#    Updated: 2023/02/06 22:40:37 by gcamargo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_FILES = main.c checks.c create_stack.c \
				clean.c swap.c push.c \
				rotate.c reverse_rotate.c \
				sort_utils.c small_sort.c small_sort_utils.c \
				big_sort.c big_sort_utils.c 

CFLAGS = -Wall -Werror -Wextra 
CC = gcc 

LIB = libft.a
LIB_PATH = ./libft

SRC_PATH = ./src
OBJ_PATH = ./objects

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ = $(addprefix $(OBJ_PATH)/, $(subst .c,.o,$(SRC_FILES)))

RM = rm -rf

all: build_libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) -g $(OBJ) -o $(NAME) -Ilibft -Llibft -lft
	@echo "\033[1;92mPush_Swap Created ✔︎\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -g -o $@ -c $< 
	
build_libft:
	@make --no-print-directory -C $(LIB_PATH) 

full_test: $(NAME)
	@echo -n "  2 args      = "
	@./push_swap $(shell shuf -i 0-10000 -n 2) | wc -l
	@echo -n "  3 args      = "
	@./push_swap $(shell shuf -i 0-10000 -n 3) | wc -l
	@echo -n "  5 args      = "
	@./push_swap $(shell shuf -i 0-10000 -n 5) | wc -l
	@echo -n "100 args      = "
	@./push_swap $(shell shuf -i 0-10000 -n 100) | wc -l
	@echo -n "500 args      = "
	@./push_swap $(shell shuf -i 0-10000 -n 500) | wc -l
	
clean:
	@$(RM) $(OBJ_PATH)
	@make --no-print-directory -C $(LIB_PATH) clean
	@echo "\033[1;93mLib Removed ✔︎\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@make --no-print-directory -C $(LIB_PATH) fclean
	@echo "\033[1;93mPush_Swap Removed ✔︎\033[0m"
	
re: fclean all

.PHONY: all build_libft re clean fclean 
