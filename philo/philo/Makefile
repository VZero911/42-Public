NAME := philo
CFLAGS := -Wall -Wextra -Werror
SRC := philo.c parsing.c utils.c data_init.c mutex_thread.c execute_philo.c getters_setters.c\

OBJ := $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re