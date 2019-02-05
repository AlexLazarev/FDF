# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazarev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 15:31:29 by alazarev          #+#    #+#              #
#    Updated: 2018/04/18 13:00:54 by alazarev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = ./sources/
OBJ_DIR = ./objects/
INC_DIR = ./includes/
LIB_DIR = ./lib/

SRC = main.c parser.c get_next_line.c draw.c check_key.c mouse.c info_table.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = $(LIB_DIR)libft/
LIBFT_INC = $(LIBFT_DIR)$(INC_DIR)
LIBFT_FLAGS = -lft -L $(LIBFT_DIR)

LIBMLX = $(LIB_DIR)libmlx.a

HEADER_FLAGS = -I $(INC_DIR) -I $(LIBFT_INC)

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
CC_FLAGS = 
CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_FLAGS) $(LIBMLX) $(MLX_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADERS_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
