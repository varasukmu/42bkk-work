NAME        = push_swap

CC          = cc
C_FLAGS     = -Wall -Wextra -Werror

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include

RESET       = \033[0m
BOLD        = \033[1m
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
CYAN        = \033[36m

CFILES      = main.c \
              easy_sort.c \
              helper.c \
              parse_utils.c \
              sort.c \
              split_utils.c \
              stack.c \
              operations/operation.c \
              operations/wrappers_operations_a.c \
              operations/wrappers_operations_b.c

SRCS        = $(addprefix $(SRC_DIR)/, $(CFILES))
OBJS        = $(addprefix $(OBJ_DIR)/, $(CFILES:.c=.o))
HEADERS     = $(INC_DIR)/push_swap.h $(INC_DIR)/struct.h

# ==============================================================================
# Rules
# ==============================================================================
all:            $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
				@mkdir -p $(dir $@)
#				@echo "$(CYAN)Compiling: $<...$(RESET)"
				@$(CC) $(C_FLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME):        $(OBJS)
				@$(CC) $(C_FLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)$(BOLD)$(NAME) is successfully compiled and ready!$(RESET)"

clean:
				@rm -rf $(OBJ_DIR)
				@echo "$(YELLOW)Objects cleaned.$(RESET)"

fclean:         clean
				@rm -f $(NAME)
				@echo "$(RED)$(NAME) completely removed.$(RESET)"

re:             fclean all

.PHONY:         all clean fclean re