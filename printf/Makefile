NAME      := libftprintf.a
CFLAGS     := -Wall -Wextra -Werror 
LIB	:= libft/libft.a

SRC	:= ft_printf.c \
	   	ft_printf_parsing.c \
		ft_printf_type.c \
		ft_printf_type2.c \
		ft_printf_utils.c \
		ft_printf_hex.c \
		check_for_flags.c \
		apply_flags.c \
		ft_pointer_to_str.c \

OBJ      := $(SRC:.c=.o)
ARFLAGS   := rcs

%.o:            %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJ) $(LIB)
		cp $(LIB) $(NAME)
		ar $(ARFLAGS) $(NAME) $(OBJ)
$(LIB):
		$(MAKE) -C libft

all:		$(NAME)

clean:
		$(MAKE) clean -C libft
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)
		rm -f $(LIB)

bonus:		$(NAME)

re:                     fclean all

.PHONY:         all clean fclean re main mainre
