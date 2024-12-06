GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m

NAME      := pipex
CFLAGS     := -Wall -Wextra -Werror 
LIB	:= libft/libft.a

SRC	:=	pipex.c validate.c multiples_pipes.c handles_child.c heredoc_main.c heredoc_utils.c \

OBJ      := $(SRC:.c=.o)

$(NAME):        $(OBJ) $(LIB)
		@echo "$(YELLOW)Linking $(NAME)...$(NC)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
		@echo "$(GREEN)Compilation terminée !$(NC)"

%.o:            %.c
		@echo "$(BLUE)Compiling $<...$(NC)"
		$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
		$(MAKE) -C libft

all:	$(NAME)

clean:
	@if [ -n "$(wildcard $(OBJ))" ]; then \
		rm -f $(OBJ); \
		echo "$(RED)Cleaned object files$(NC)"; \
		$(MAKE) clean -C libft; \
		echo "$(RED)Cleaned libft object files$(NC)"; \
	else \
		echo "$(YELLOW)No object files to clean$(NC)"; \
	fi

fclean:
	@if [ -f $(NAME) ]; then \
		rm -f $(OBJ); \
		rm -f $(NAME); \
		echo "$(RED)Cleaned object files$(NC)"; \
		$(MAKE) fclean -C libft; \
		echo "$(RED)Cleaned libft object files$(NC)"; \
		echo "$(RED)Removed $(NAME)$(NC)"; \
	else \
		echo "$(YELLOW)No executable to remove$(NC)"; \
	fi

re:             fclean all

.PHONY:         all clean fclean re bonus
