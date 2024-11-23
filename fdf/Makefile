NAME := fdf
CFLAGS := -Wall -Wextra -Werror
LIB := libft/libft.a
MINILIBX := minilibx/libmlx.a
SRC := fdf.c read_file.c parsing_utils.c utils.c data_init.c draw_map.c projection.c colors.c \

OBJ := $(SRC:.c=.o)

LIBS := -lX11 -lXext -lm -lz

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(MINILIBX) $(LIBS)

$(LIB):
	$(MAKE) -C libft

$(MINILIBX):
	$(MAKE) -C minilibx

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re