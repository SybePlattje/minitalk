SERVER_NAME = server
CLIENT_NAME = client
HEADER = ./includes/minitalk.h

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SERVER_SRC = ./src/server.c
CLIENT_SRC = ./src/client.c

OBJ_DIR = ./obj
$(shell mkdir -p $(OBJ_DIR))

SERVER_OBJ = $(OBJ_DIR)/$(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(OBJ_DIR)/$(CLIENT_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(SERVER_NAME): $(SERVER_OBJ) $(LIBFT) $(HEADER)
	@cp $(HEADER) $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re