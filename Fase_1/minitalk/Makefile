# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 17:20:46 by gcamargo          #+#    #+#              #
#    Updated: 2023/01/06 19:43:41 by gcamargo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CC_FLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = ./libft
BUILD_DIR = ./build
LIBFT_FILE = $(LIBFT_DIR)/libft.a

HEADER = ./
SRC_DIR = ./src
OBJ_DIR = $(BUILD_DIR)/obj
HEADER_FILES = $(addprefix $(HEADER)/, minitalk.h)
CLIENT_SRC_FILES = $(addprefix $(SRC_DIR)/, client.c error.c)
CLIENT_OBJ_FILES = $(subst $(SRC_DIR), $(OBJ_DIR), $(CLIENT_SRC_FILES:.c=.o))
SERVER_SRC_FILES = $(addprefix $(SRC_DIR)/, server.c error.c)
SERVER_OBJ_FILES = $(subst $(SRC_DIR), $(OBJ_DIR), $(SERVER_SRC_FILES:.c=.o))

INCLUDE_FLAGS = -I$(HEADER) -I$(LIBFT_DIR)
LIB_FLAGS = -L$(LIBFT_DIR) -lft

CLIENT_NAME = $(BUILD_DIR)/client
SERVER_NAME = $(BUILD_DIR)/server

all: client server

client: $(CLIENT_NAME)

server: $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT_FILE) $(CLIENT_OBJ_FILES) $(HEADER_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(CLIENT_OBJ_FILES) $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $@

$(SERVER_NAME): $(LIBFT_FILE) $(SERVER_OBJ_FILES) $(HEADER_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(SERVER_OBJ_FILES) $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $@

$(LIBFT_FILE):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $< $(INCLUDE_FLAGS) -c -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:
	make -C $(LIBFT_DIR) fclean
	$(RM) $(BUILD_DIR)

norm:
	norminette

re:	fclean all

.PHONY: all clean client fclean norm re server