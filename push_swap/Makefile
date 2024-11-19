NAME      := push_swap
CFLAGS     := -Wall -Wextra -Werror 
LIB	:= libft/libft.a

SRC	:=	commands/push.c commands/rev_rotate.c commands/rotate.c commands/swap.c \
		utils/calcul_utils.c utils/get_functions.c utils/stacks_init.c utils/stacks_utils.c \
		parsing/ft_atol.c parsing/my_split.c parsing/push_swap.c parsing/sort_int_tab.c \
		parsing/parsing.c parsing/parsing_utils.c algo/push_swap_algo.c algo/sort_utils.c \

OBJ      := $(SRC:.c=.o)

%.o:            %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJ) $(LIB)
		cp $(LIB) $(NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

$(LIB):
		$(MAKE) -C libft

all:	$(NAME)

bonus:
		$(MAKE) -C bonus

clean:
		$(MAKE) clean -C libft
		rm -f $(OBJ)
		$(MAKE) clean -C bonus

fclean:         clean
		rm -f $(NAME)
		rm -f $(LIB)
		$(MAKE) fclean -C bonus

re:             fclean all

.PHONY:         all clean fclean re bonus
