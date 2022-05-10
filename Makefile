SERVER = server

CLIENT = client

CFLAGS = -Wall -Wextra -Werror

NAME = server_bonus

CLIENT2 = client_bonus

all : $(SERVER) $(CLIENT)

$(SERVER) : tools.c server.c minitalk.h
		@$(CC) $(CFLAGS) server.c tools.c -o $@
		
$(CLIENT) : tools.c client.c minitalk.h
		@$(CC) $(CFLAGS) client.c tools.c -o $@

bonus : $(NAME) $(CLIENT2)

$(NAME) : tools.c server_bonus.c minitalk_bonus.h
		@$(CC) $(CFLAGS) server_bonus.c tools.c -o $@

$(CLIENT2) : tools.c client_bonus.c minitalk_bonus.h
		@$(CC) $(CFLAGS) client_bonus.c tools.c -o $@

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf server client server_bonus client_bonus

re : fclean all