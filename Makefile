NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra
AR = ar -rcs
SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	Make -C ./printf
	cp printf/libprintf.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	Make -C clean ./libft
	Make -C clean ./printf
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re