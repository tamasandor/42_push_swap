NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra
AR = ar -rcs
SRC = ./src/operations.c ./src/parser.c ./src/stack.c ./src/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./include/libft
	cp ./include/libft/libft.a ./libft.a
	$(CC) $(FLAGS) $(OBJ) libft.a -o $(NAME)

clean:
	$(MAKE) -C ./include/libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ./include/libft fclean
	rm -f $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re