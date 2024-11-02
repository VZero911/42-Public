NAME      := push_swap
CFLAGS     := -Wall -Wextra -Werror 
LIB	:= libft/libft.a

SRC	:= main.c \
	   my_split.c \
	   stack_init.c \
	   stack_utils.c \
	   errors_free.c \
	   commands_swap.c \
	   commands_push.c \

OBJ      := $(SRC:.c=.o)

%.o:            %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJ) $(LIB)
		cp $(LIB) $(NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
$(LIB):
		$(MAKE) -C libft

all:            $(NAME)

clean:
		$(MAKE) clean -C libft
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)
		rm -f $(LIB)

re:                     fclean all

.PHONY:         all clean fclean re
