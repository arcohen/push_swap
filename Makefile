CHKR = checker
PS = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
C_INC = -I ./checkr/includes/
P_INC = -I ./p_swap/includes/
CH_SRCS = checkr/srcs/error_check.c checkr/srcs/instructions.c checkr/srcs/main.c checkr/srcs/make_stack.c checkr/srcs/operations.c
PS_SRCS = p_swap/srcs/error_check.c p_swap/srcs/instructions.c p_swap/srcs/main.c p_swap/srcs/make_stack.c p_swap/srcs/operations.c p_swap/srcs/tools.c
LIBFT = ./libft/libft.a
RM = rm -rf
NORM = norminette

all: $(LIBFT)
	@$(CC) -o $(CHKR) $(CH_SRCS) $(CFLAGS) $(C_INC) $(LIBFT)
	@$(CC) -o $(PS) $(PS_SRCS) $(CFLAGS) $(P_INC) $(LIBFT)
	@echo "\033[32m[Compiled]\033[0m"

checker: clean_chkr
	@$(RM) $(CHKR)
	@$(CC) -o $(CHKR) $(CH_SRCS) $(CFLAGS) $(C_INC) $(LIBFT)
	@echo "\033[32m[Compiled Checker]\033[0m"

push_swap: clean_ps
	@$(CC) -o $(PS) $(PS_SRCS) $(CFLAGS) $(P_INC) $(LIBFT)
	@echo "\033[32m[Compiled Push_Swap]\033[0m"

clean_chkr:
	@$(RM) $(CHKR)

clean_ps:
	@$(RM) $(PS)

$(LIBFT):
	@make re -C ./libft/
	@echo "\033[32m[Compiled Libft]\033[0m"

clean:
	@make clean -C ./libft/
	@$(RM) $(CHKR)
	@$(RM) $(PS)
	@echo "\033[31m[Cleaned]\033[0m"

fclean: clean
	@make fclean -C ./libft/
	@echo "\033[031m[Fucking Cleaned]\033[0m"

re: fclean all
