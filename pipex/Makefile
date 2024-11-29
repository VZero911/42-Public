GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m

NAME      := pipex
CFLAGS     := -Wall -Wextra -Werror 
LIB	:= libft/libft.a

SRC	:=	pipex.c validate.c execute_pipex.c path.c \

OBJ      := $(SRC:.c=.o)

%.o:            %.c
		@echo "$(BLUE)Compiling $<...$(NC)"
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJ) $(LIB)
		@echo "$(YELLOW)Linking $(NAME)...$(NC)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
		@echo "$(GREEN)Compilation terminée !$(NC)"

$(LIB):
		$(MAKE) -C libft

all:	$(NAME)

clean:
	@if [ -n "$(wildcard $(OBJ))" ]; then \
		rm -f $(OBJ); \
		$(MAKE) clean -C libft; \
		echo "$(RED)Cleaned object files$(NC)"; \
	else \
		echo "$(YELLOW)No object files to clean$(NC)"; \
	fi

fclean:
	@if [ -f $(NAME) ]; then \
		rm -f $(OBJ); \
		rm -f $(NAME); \
		$(MAKE) fclean -C libft; \
		echo "$(RED)Cleaned object files$(NC)"; \
		echo "$(RED)Removed $(NAME)$(NC)"; \
	else \
		echo "$(YELLOW)No executable to remove$(NC)"; \
	fi

re:             fclean all

.PHONY:         all clean fclean re bonus