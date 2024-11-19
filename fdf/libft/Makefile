NAME      := libft.a
CFLAGS     := -Wall -Wextra -Werror -fPIE

SRC      := ft_isalpha.c \
			 ft_isalnum.c \
			 ft_isdigit.c \
			 ft_isascii.c \
			 ft_isprint.c \
			 ft_strlen.c \
			 ft_memset.c \
			 ft_bzero.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_strlcpy.c \
			 ft_strlcat.c \
			 ft_toupper.c \
			 ft_tolower.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_atoi.c \
			 ft_putchar_fd.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_strncmp.c \
			 ft_strnstr.c \
			 ft_putstr_fd.c \
			 ft_calloc.c \
			 ft_strdup.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_substr.c \
			 ft_striteri.c \
			 ft_strmapi.c \
			 ft_strjoin.c \
			 ft_itoa.c \
			 ft_strtrim.c \
			 ft_split.c \
			 ft_printf.c \
			 ft_printf_parsing.c \
			 ft_printf_utils.c \
			 ft_printf_type.c \
			 ft_printf_type2.c \
			 ft_printf_hex.c \
			 get_next_line.c \
			 get_next_line_utils.c \

BONUS	:= ft_lstnew_bonus.c \
	   	ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJ      := $(SRC:.c=.o)
ARFLAGS   := rcs
RM		    := rm -f
BONUSOBJ	:= $(BONUS:.c=.o)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus:		$(OBJ) $(BONUSOBJ)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(BONUSOBJ)

all:		$(NAME)

clean:
			$(RM) $(OBJ) $(BONUSOBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
