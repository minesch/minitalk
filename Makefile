SERVER = server

CLIENT = client

CC = cc

FLAGS = -Wall -Wextra -Werror -g

FT_PRINTF = libftprintf.a

all: $(FT_PRINTF) $(SERVER) $(CLIENT)

$(FT_PRINTF):
	@make -C ft_printf

%.o : %.c
	$(CC) $(FLAGS) $< -c -I includes

clean:
	@make clean -C ft_printf
	@rm -f *.o

fclean: clean
	@make fclean -C ft_printf
	@rm -f *.a

re: clean fclean all
