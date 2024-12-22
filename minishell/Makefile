NAME      := minishell
CFLAGS     := -g -Wall -Wextra -Werror 
LIB	:= libft/libft.a

SRC	:=	parsing/redirections_utils.c minishell.c utils.c signals.c \
		parsing/command_utils.c parsing/redirections.c \
		parsing/token_utils.c parsing/parsing.c \
		exec/exec_shell.c exec/builtins/cd.c \
		exec/builtins/env.c exec/builtins/env_utils.c exec/builtins/export.c \
		exec/builtins/unset.c exec/builtins/pwd.c parsing/heredoc.c \
		parsing/command_free.c parsing/quote_utils.c \
		parsing/quotes.c exec/builtins/neosnitch.c exec/builtins/echo.c \
		exec/external_command.c exec/multiples_cmd.c exec/exec_utils.c \

OBJ      := $(SRC:.c=.o)

%.o:            %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJ) $(LIB)
		cp $(LIB) $(NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) -lreadline

$(LIB):
		$(MAKE) -C libft

all:	$(NAME)


clean:
		$(MAKE) clean -C libft
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)
		rm -f $(LIB)

re:             fclean all

.PHONY:         all clean fclean re