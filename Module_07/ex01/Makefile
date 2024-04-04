# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 18:09:15 by lyandriy          #+#    #+#              #
#    Updated: 2024/04/04 18:09:25 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = iter

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