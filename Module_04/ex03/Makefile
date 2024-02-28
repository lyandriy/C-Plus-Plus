# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 20:20:46 by lyandriy          #+#    #+#              #
#    Updated: 2024/02/25 15:34:29 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	  AMateria.cpp \
	  Character.cpp \
	  Cure.cpp \
	  Ice.cpp \
	  MateriaSource.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = Materia

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