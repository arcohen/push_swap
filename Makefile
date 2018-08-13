# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 14:36:14 by arcohen           #+#    #+#              #
#    Updated: 2018/08/13 12:27:50 by arcohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
CC = gcc -o
FLAGS = -Wall -Wextra -Werror
INC = -I ./includes/
LIB = ./libft/
SRC = ./srcs/main.c ./srcs/make_stack.c ./srcs/error_check.c 

RM = rm -rf

$(NAME1):2
	@$(CC) $(NAME) $(FLAGS) $(SRC) $(INC) -L libft/ -lft
	@echo "-- Checker Compiled Successfully --"

all: $(NAME)

clean:
	@make clean -C $(LIB)

fclean:
	@make fclean -C $(LIB)
	@$(RM) $(NAME)
	@echo "-- Player Cleaned --"


re: fclean all