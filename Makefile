NAME = pipex
LIBFT = ./Libft

SRC = \
		main.c \
		child_process.c \
		get_next_line.c \
		get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)
FLAGS = -Wall -Werror -Wextra
CC = gcc

$(NAME) :
	make -C $(LIBFT)
	$(CC) $(FLAGS) $(SRC) ./Libft/libft.a -o $(NAME)

all : $(NAME)

clean :
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean : clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re : fclean all