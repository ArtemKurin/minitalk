CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCES = main_client.c main_server.c

OBJECTS = $(SOURCES:.c=.o)

all: server client

server: main_server.o libft
	$(CC) $(FLAGS) -o server main_server.o -Llibft -lft

client: main_client.o libft
	$(CC) $(FLAGS) -o client main_client.o -Llibft -lft

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re server client
