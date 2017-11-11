# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 21:06:58 by fsabatie          #+#    #+#              #
#    Updated: 2017/11/06 21:07:01 by fsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = srcs
INC_PATH = includes

SRC_NAME =	ft_fill_it.c \
			ft_checkers.c

LIB_NAME = libft.a
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
LIB = $(addprefix $(INC_PATH)/,$(LIB_NAME))
CPPFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(CPPFLAGS) -I$(INC_PATH) -c $(SRC)
	@gcc $(CPPFLAGS) $(OBJ_NAME) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJ_NAME)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
