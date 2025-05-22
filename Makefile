NAME = blocks
INC	= ./inc
CC	= cc
HEADERS	= $(INC)/data.h
HEADER_DIRS = -I$(INC) -I./minilibx-linux
FLAGS	= -Wall -Wextra -Werror -g3 $(HEADER_DIRS)
MLX_LINKS = -L./minilibx-linux -lmlx -lXext -lX11 -lm
SRC_DIR	= ./src
OBJ_DIR = ./obj
SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/core/init.c \
		$(SRC_DIR)/hooks/key_inputs.c \
		$(SRC_DIR)/exit_cleanup.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
NORMAL	= \033[0m

all: $(NAME)

$(OBJ_DIR):
	@echo "${YELLOW}Creating object directory $(OBJ_DIR)...${NORMAL}"
	@mkdir -p $(OBJ_DIR)
	@echo "${GREEN}    Created $(OBJ_DIR).${NORMAL}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@echo "${YELLOW}Compiling $< into $@...${NORMAL}"
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "${GREEN}    $@ compiled successfully.${NORMAL}"

$(NAME): $(OBJS)
	@echo "${YELLOW}Linking .o files to $(NAME)...${NORMAL}"
	$(CC) $(FLAGS) $(OBJS) $(MLX_LINKS) -o $(NAME)
	@echo "${GREEN}   $(NAME) is linked up successfully.${NORMAL}"

clean:
	@echo "${PURPLE} Cleaning and deleteing $(OBJ_DIR)...${NORMAL}"
	@rm -rf $(OBJ_DIR)
	@echo "${GREEN}    $(OBJ_DIR) cleaned successfully.${NORMAL}"

fclean: clean
	@echo "${RED} Deleting $(NAME)...${NORMAL}"
	@rm $(NAME)
	@echo "${GREEN}    $(NAME) deleted successfully.${NORMAL}"

re: fclean all
	@echo "${BLUE} Relinking $(NAME)...${NORMAL}"
	@echo "${GREEN}    $(NAME) relinked successfully.${NORMAL}"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
	
.PHONY: all clean fclean re
