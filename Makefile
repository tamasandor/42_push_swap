NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra
AR = ar -rcs
SRC = ./src/operations.c ./src/parser.c ./src/stack.c ./src/utils.c ./src/main.c ./src/pos_and_cost.c ./src/effective_adjust.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./include/libft
	mv ./include/libft/libft.a ./libft.a
	$(CC) $(FLAGS) $(OBJ) libft.a -o $(NAME)

clean:
	$(MAKE) -C ./include/libft clean
	rm -f $(OBJ) libft.a

fclean: clean
	$(MAKE) -C ./include/libft fclean
	rm -f $(NAME)

re: fclean all

test3:		$(NAME)	
		$(eval ARG = $(shell shuf -i 0-50 -n 3))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test5:		$(NAME)	
		$(eval ARG = $(shell shuf -i 0-50 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test100:	$(NAME)	
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500:	$(NAME)	
		$(eval ARG = $(shell shuf -i 0-2000 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re