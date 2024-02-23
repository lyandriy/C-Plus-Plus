# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 18:13:04 by lyandriy          #+#    #+#              #
#    Updated: 2024/02/23 20:21:34 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	  ClapTrap.cpp \
	  ScavTrap.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = ScavTrap

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