# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: felsanch <felsanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 18:47:02 by felsanch          #+#    #+#              #
#    Updated: 2023/07/26 21:10:37 by felsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all = $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re