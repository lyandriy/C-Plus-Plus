# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 17:48:15 by lyandriy          #+#    #+#              #
#    Updated: 2024/02/04 16:59:53 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Contact.cpp \
	  PhoneBook.cpp \
	  main.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = phonebook

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