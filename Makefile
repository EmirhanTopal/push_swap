NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap_main.c \
		control_operations.c \
		stack_operations.c \
		ft_push.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		ft_swap.c \
		ft_split.c \
		ft_split_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
