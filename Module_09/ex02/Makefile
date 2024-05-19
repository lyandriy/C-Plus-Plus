# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 19:24:25 by lyandriy          #+#    #+#              #
#    Updated: 2024/05/19 16:47:56 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = main.cpp \
	  PmergeMeVector.cpp \
	  PmergeMeDeque.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = PmergeMe

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