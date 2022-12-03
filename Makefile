SERVER = server

CLIENT = client

SRC = $(wildcard ft_*.c)

SERVER_OBJ = $(patsubst %.c, %.o, server.c)

CLIENT_OBJ = $(patsubst %.c, %.o, client.c)

SRC_OBJ = $(patsubst %.c, %.o, $(SRC))

CC = cc

FLAGS = -Wall -Wextra -Werror -g -I.

all: $(SERVER) $(CLIENT)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(SERVER) : $(SRC_OBJ) $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) $(SRC_OBJ) -o $(SERVER)

$(CLIENT) : $(SRC_OBJ) $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(SRC_OBJ) -o $(CLIENT)

clean:
	@rm -f *.o

fclean: clean
	@rm -rf $(CLIENT) $(SERVER)

re: clean fclean all
