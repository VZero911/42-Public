NAME      := checker
CFLAGS    := -Wall -Wextra -Werror
LIB	      := ../libft/libft.a
OUTPUT_DIR := ../

SRC	      :=	commands/push.c commands/rev_rotate.c commands/rotate.c commands/swap.c \
		        checker.c ft_atol.c my_split.c stacks_init.c \

OBJ       := $(SRC:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT_DIR)$(NAME): $(OBJ) $(LIB)
		$(CC) $(CFLAGS) -o $(OUTPUT_DIR)$(NAME) $(OBJ) $(LIB)

$(LIB):
		$(MAKE) -C ../libft

all: $(OUTPUT_DIR)$(NAME)

clean:
		$(MAKE) clean -C ../libft
		rm -f $(OBJ)

fclean: clean
		rm -f $(OUTPUT_DIR)$(NAME)

re: fclean all

.PHONY: all clean fclean re
