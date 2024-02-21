NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra
AR = ar -rcs
SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	Make -C ./include/printf
	cp ./include/printf/libftprintf.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	Make -C ./include/libft clean
	Make -C ./include/printf clean
	rm -f $(OBJ)

fclean: clean
	Make -C ./include/libft fclean
	Make -C ./include/printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re