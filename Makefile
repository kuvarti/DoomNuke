DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET = [0m
BOLD = [1m

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = lib

# Add new folders here
# Yeni klasorleri buraya ekle
SRC += $(shell find src -name "*.c")

OBJ += $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB = lib/libft/libft.a -L$(PWD)/lib/sdl2/build -lSDL3

NAME = doom-nukem

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	# Linux specific flags
	LIB += -Wl,-rpath,$(PWD)/lib/sdl2/build
else ifeq ($(UNAME_S),Darwin)
	# macOS specific flags
	LIB += -Wl,-rpath,@executable_path/lib/sdl2/build
endif

CC += -g
CFLAGS += -Wall -Wextra
CFLAGS += -I $(INC_DIR) -I lib/libft -I lib/sdl2/include/SDL3 -I lib/sdl2/build/include/SDL3 -I lib/sdl2/include -I lib/sdl2/build/include

all: $(OBJ_DIR) $(LIB) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@
	@mkdir -p $@/config
	@mkdir -p $@/Events
	@echo "$(MAGENTA)Object directories created..."

$(LIB): sdl_init
	@make -C lib/libft
	@make -C lib/sdl2/build

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB) 
	@echo "$(GREEN)Compiled { $(CYAN)$(NAME) $(GREEN)}"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(CFLAGS) 
	@echo "$(GREEN)Compiled {$(RED) $@ $(GREEN)}"

src: clean all

# RESET SDL
sdl_reset: sdl_del sdl_init

# DELETE SDL
sdl_del:
	@rm -rf lib/sdl2/build

# INIT SDL
sdl_init:
	@cmake -S lib/sdl2 -B lib/sdl2/build && cmake --build lib/sdl2/build

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@echo "$(YELLOW)Object directory $(RED)DELETED"

fclean: clean sdl_del
	@make fclean -C lib/libft
	@echo "$(YELLOW)$(NAME) $(RED)DELETED"

re: fclean all

.PHONY: all clean fclean re