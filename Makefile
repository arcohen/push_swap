# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 14:36:14 by arcohen           #+#    #+#              #
#    Updated: 2018/09/04 20:40:53 by arcohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
CC = gcc -o
FLAGS = -Wall -Wextra -Werror
INC = -I ./includes/
SRC = ./checker/srcs/main.c ./checker/srcs/make_stack.c ./checker/srcs/error_check.c ./checker/srcs/instructions.c ./checker/srcs/operations.c

NAME2 = push_swap
SRC2 = ./push_swap/srcs/error_check.c ./push_swap/srcs/instructions.c ./push_swap/srcs/main.c ./push_swap/srcs/make_stack.c ./push_swap/srcs/operations.c ./push_swap/srcs/tools.c

RM = rm -f

$(NAME):
	@$(CC) $(NAME1) $(FLAGS) $(SRC)
	@$(CC) $(NAME2) $(FLAGS) $(SRC)
	@echo "-- Checker Compiled Successfully --"
	@echo "-- Push_Swap Compiled Successfully --"

all: $(NAME)

clean:
	@echo "-- Object Files Removed --"

fclean:
	@$(RM) $(NAME1)
	@$(RM) $(NAME2)
	@echo "-- Cleaned --"

re: fclean all