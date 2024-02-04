# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 18:57:30 by lyandriy          #+#    #+#              #
#    Updated: 2024/02/04 16:59:47 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Account.cpp \
	  tests.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = account

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
all: $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re