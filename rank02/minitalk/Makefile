CC =            cc
C_FLAGS =       -Wall -Wextra -Werror

SRC_DIR =       src
OBJ_DIR =       obj
BIN_DIR =       bin

CLIENT_CFILES = $(SRC_DIR)/client.c $(SRC_DIR)/utils.c
SERVER_CFILES = $(SRC_DIR)/server.c $(SRC_DIR)/utils.c

NAME_C =        $(BIN_DIR)/client
NAME_S =        $(BIN_DIR)/server

OBJS_CLIENT =   $(CLIENT_CFILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_SERVER =   $(SERVER_CFILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: 			$(NAME_C) $(NAME_S)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(BIN_DIR):
				mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/minitalk.h | $(OBJ_DIR)
				$(CC) $(C_FLAGS) -c $< -o $@

$(NAME_C): 		$(OBJS_CLIENT) | $(BIN_DIR)
				$(CC) $(C_FLAGS) $(OBJS_CLIENT) -o $(NAME_C)

$(NAME_S): 		$(OBJS_SERVER) | $(BIN_DIR)
				$(CC) $(C_FLAGS) $(OBJS_SERVER) -o $(NAME_S)

clean:
				rm -rf $(OBJ_DIR)

fclean: 		clean
				rm -rf $(BIN_DIR)

re: 			fclean all

.PHONY: 		all clean fclean re