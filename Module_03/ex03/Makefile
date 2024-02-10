# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 18:14:13 by lyandriy          #+#    #+#              #
#    Updated: 2024/02/10 18:14:38 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	  ClapTrap.cpp \
	  ScavTrap.cpp \
	  FragTrap.cpp \
	  DiamondTrap.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = ClapTrap

OBJDIR = obj
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