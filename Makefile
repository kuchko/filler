# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okuchko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 16:03:56 by okuchko           #+#    #+#              #
#    Updated: 2019/01/16 16:05:31 by okuchko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = okuchko.filler

OBJ_DIR = ./obj/

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SOURCES = main.c map_piece.c solving.c

OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))
# OBJECTS = $(SOURCES:.c=.o)

INC = $(INC_DIR)libft.a
INC_DIR = libft/
INCLUDES = $(INC_DIR)inc/
INC_FLAGC = -L $(INC_DIR) -lft
HEADER_FLAGS =	-I $(INCLUDES)  -I filler.h

all: $(NAME)

$(NAME): $(INC) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(INC_FLAGC) -o $(NAME)
$(INC):
	make -C $(INC_DIR)

$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		$(CC) $(CC_FLAGS) -c $< -o $@ $(HEADER_FLAGS)

clean:
#	rm -f $(OBJECTS)
	@rm -rf $(OBJ_DIR)
	make clean -C $(INC_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(INC_DIR)

re:	fclean all
