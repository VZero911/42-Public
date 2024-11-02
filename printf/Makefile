NAME      := libftprintf.a
CFLAGS     := -Wall -Wextra -Werror 
LIB	:= libft/libft.a

SRC	:= ft_printf.c \
	   	ft_printf_parsing.c \
		ft_printf_type.c \
		ft_printf_type2.c \
		ft_printf_utils.c \
		ft_printf_hex.c

OBJ      := $(SRC:.c=.o)
ARFLAGS   := rcs

MAIN	:= main.c
MAIN_NAME	:= printf_exec
MAIN_OBJ	:=$(MAIN:.c = .o)

%.o:            %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJ) $(LIB)
		cp $(LIB) $(NAME)
		ar $(ARFLAGS) $(NAME) $(OBJ)
$(LIB):
		$(MAKE) -C $$(dirname $(LIB))

main:		$(MAIN_OBJ) $(NAME)
		$(CC) $(CFLAGS) -o $(MAIN_NAME) $(MAIN_OBJ) $(NAME)

all:            $(NAME)

clean:
		$(MAKE) clean -C $$(dirname $(LIB))
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)
		rm -f $(LIB)

mainfclean:	fclean
		rm -f $(MAIN_NAME)

mainre:		mainfclean main

re:                     fclean all

.PHONY:         all clean fclean re main mainre
