CC = cc
NAME = a.out
FLAGS = -Wall -Wextra -Werror -D

all:
	$(CC) $(FLAGS) BUFFER_SIZE=$(bs) get_next_line.c get_next_line_utils.c main.c -I . && ./a.out

clean:
	rm -f $(NAME)

