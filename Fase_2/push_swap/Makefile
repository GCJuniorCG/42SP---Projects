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

CFLAGS = -Wall -Werror -Wextra 
CC = clang 

LIBFT = libft.a
LIBFT_PATH = ./libft

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects

SOURCES_FILES = main.c checks.c create_stack.c \
				clean.c swap.c push.c \
				rotate.c reverse_rotate.c \
				sort_utils.c small_sort.c small_sort_utils.c \
				big_sort.c big_sort_utils.c 

SOURCES = $(addprefix $(SOURCES_PATH)/, $(SOURCES_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/, $(subst .c,.o,$(SOURCES_FILES)))

REMOVE = rm -rf

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

all: build_libft $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -g $(OBJECTS) -o $(NAME) -Ilibft -Llibft -lft
	$(MSG1)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c 
	mkdir -p $(OBJECTS_PATH)
	$(CC) $(CFLAGS) -g -o $@ -c $< 
	
build_libft:
	@make --no-print-directory -C $(LIBFT_PATH) 

full_test: $(NAME)
#/@clear
	@echo -n "  2 args      = "
	@valgrind -q ./push_swap $(shell shuf -i 0-10000 -n 2) | wc -l
	@echo -n "  3 args      = "
	@./push_swap $(shell shuf -i 0-10000 -n 3) | wc -l
	@echo -n "  5 args      = "
	@./push_swap $(shell shuf -i 0-10000 -n 5) | wc -l
	@echo -n "100 args      = "
	@./push_swap $(shell shuf -i 0-10000 -n 100) | wc -l
	@echo -n "500 args      = "
	@./push_swap $(shell shuf -i 0-10000 -n 500) | wc -l

clean:
	@$(REMOVE) $(OBJECTS_PATH)
	@make --no-print-directory -C $(LIBFT_PATH) clean
	$(MSG2)

fclean: clean
	@$(REMOVE) $(NAME)
	@make --no-print-directory -C $(LIBFT_PATH) fclean
	$(MSG2)
re: fclean all

.PHONY: all build_libft re clean fclean 