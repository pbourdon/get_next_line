# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 05:19:18 by pbourdon          #+#    #+#              #
#    Updated: 2015/12/21 07:18:30 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/

SRC_NAME = ft_get_next_line.c \

OBJ_PATH = ./obj/

INC_PATH = ./

LIB_NAME = ft_get_next_line.h

NAME = get_next_line.a

CC = gcc
CFLAGS = -Werror -Wall - Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(SRC_PATH), $(SRC_NAME))
LIB = $(addprefix -L, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATHTH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
		$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<
