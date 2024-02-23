# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 20:32:14 by lyandriy          #+#    #+#              #
#    Updated: 2024/02/23 20:21:23 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	  Animal.cpp \
	  Dog.cpp \
	  Cat.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = Animal

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re