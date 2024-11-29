NAME      := libft.a
CFLAGS     := -Wall -Wextra -Werror

SRC      := alpha/ft_isalpha.c \
			 alpha/ft_isalnum.c \
			 alpha/ft_isdigit.c \
			 alpha/ft_isascii.c \
			 alpha/ft_isprint.c \
			 alpha/ft_toupper.c \
			 alpha/ft_tolower.c \
			 other/ft_bzero.c \
			 other/ft_atoi.c \
			 other/ft_calloc.c \
			 other/ft_itoa.c \
			 fd/ft_putchar_fd.c \
			 fd/ft_putstr_fd.c \
			 fd/ft_putendl_fd.c \
			 fd/ft_putnbr_fd.c \
			 mem/ft_memmove.c \
			 mem/ft_memcpy.c \
			 mem/ft_memset.c \
			 mem/ft_memchr.c \
			 mem/ft_memcmp.c \
			 str/ft_strlen.c \
			 str/ft_strlcpy.c \
			 str/ft_strlcat.c \
			 str/ft_strchr.c \
			 str/ft_strrchr.c \
			 str/ft_strncmp.c \
			 str/ft_strnstr.c \
			 str/ft_strdup.c \
			 str/ft_substr.c \
			 str/ft_striteri.c \
			 str/ft_strjoin.c \
			 str/ft_strmapi.c \
			 str/ft_strtrim.c \
			 str/ft_split.c \
			 printf/ft_printf.c \
			 printf/ft_printf_parsing.c \
			 printf/ft_printf_utils.c \
			 printf/ft_printf_type.c \
			 printf/ft_printf_type2.c \
			 printf/ft_printf_hex.c \
			 gnl/get_next_line.c \
			 gnl/get_next_line_utils.c \
			 free/ft_free_char_tab.c \

BONUS	:= lst/ft_lstnew_bonus.c \
	   	lst/ft_lstadd_front_bonus.c \
		lst/ft_lstsize_bonus.c \
		lst/ft_lstlast_bonus.c \
		lst/ft_lstadd_back_bonus.c \
		lst/ft_lstdelone_bonus.c \
		lst/ft_lstclear_bonus.c \
		lst/ft_lstiter_bonus.c \
		lst/ft_lstmap_bonus.c

OBJ      := $(SRC:.c=.o)
ARFLAGS   := rcs
RM		    := rm -f
BONUSOBJ	:= $(BONUS:.c=.o)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus:		$(OBJ) $(BONUSOBJ)
			@$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(BONUSOBJ)

all:		$(NAME)

clean:
			@$(RM) $(OBJ) $(BONUSOBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
