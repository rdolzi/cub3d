NAME = cub3d

SRC_DIRS = ./src 

SRCS = ./src/main.c
GNL = $(wildcard ./src/get_next_line/*.c)
BUILDER = $(wildcard ./src/builder/*.c)
CHECKER   =  $(wildcard ./src/checker/*.c)
ENGINE = $(wildcard ./src/engine/*.c)
INITIALIZER = $(wildcard ./src/initializer/*.c)
RAYCASTER = $(wildcard ./src/raycaster/*.c)
UTILS = $(wildcard ./src/utils/*.c)

FLAGS = -Wextra -Werror -Wall

CC = gcc ${FLAGS}
RM = rm -f

# Determine platform (Linux or macOS)
UNAME_S = $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    MLX_DIR = mlx_linux
    MLX_FLAGS = -L$(MLX_DIR)/libmlx.a -L ./mlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
else
    MLX_DIR = mlx_mac
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif


OBJS = ${SRCS:.c=.o} ${GNL:%.c=%.o} ${BUILDER:%.c=%.o} ${CHECKER:%.c=%.o} ${ENGINE:%.c=%.o} ${INITIALIZER:%.c=%.o} ${RAYCASTER:%.c=%.o} ${UTILS:%.c=%.o}


RED		=	\033[31m
GREEN	=	\033[32m
BLUE	=	\033[34m
CYAN	=	\033[36m
BOLD	=	\033[1m
UNDER	=	\033[4m
END		=	\033[0m
RESET	=   \033[0;0m

SRC_COUNT     = 0
SRC_COUNT_TOT := $(shell find $(SRC_DIRS) -name '*.c' | wc -l) 
SRC_PCT       = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

OBJ_DIR = ./obj

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,${SRCS}) \
       $(patsubst %.c,$(OBJ_DIR)/%.o,${GNL}) \
       $(patsubst %.c,$(OBJ_DIR)/%.o,${BUILDER}) \
       $(patsubst %.c,$(OBJ_DIR)/%.o,${CHECKER}) \
       $(patsubst %.c,$(OBJ_DIR)/%.o,${ENGINE}) \
       $(patsubst %.c,$(OBJ_DIR)/%.o,${INITIALIZER}) \
       $(patsubst %.c,$(OBJ_DIR)/%.o,${RAYCASTER}) \
       $(patsubst %.c,$(OBJ_DIR)/%.o,${UTILS})

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@if [ "$(UNAME_S)" = "Linux" ]; then \
		$(CC) -g -c $< -o $@; \
	else \
		$(CC) -Imlx -g -c $< -o $@; \
	fi
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(eval SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT)))
	@printf "\r$(BOLD)$(GREEN)[%d/%d] 😊(%d%%)$(END)$(BOLD)$(BLUE)%-40s" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT) $<

		
$(NAME): $(OBJS)
	@($(MAKE) -C $(MLX_DIR) > /dev/null 2>&1 &); \
	 wait $$!; \
	 printf "$(UNDER)$(BOLD)$(CYAN)\nCompiling mlx library. Please wait...\n$(RESET)$(BOLD)"; \
	 while [ ! -f $(MLX_DIR)/libmlx.a ]; do \
		printf "."; \
		sleep 1; \
	 done; \
	 $(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME); \
	 printf "\n"; \
	 printf "\n"; \
	 printf "\n"; \
	 printf "                             (      \n"; \
	 printf "         (           (      ))\\ )   \n"; \
	 printf "         )\\     (  ( )\\  ( /(()/(   \n"; \
	 printf "       (((_)    )\\ )((_) )\\()/(_))  \n"; \
	 printf "       )\\___ _ ((_((_)_ ((_)(_))_   \n"; \
	 printf "      ((/ __| | | || _ |__ (_|   \\  \n"; \
	 printf "       | (__| |_| || _ \\|_ \\ | |) | \n"; \
	 printf "        \\___|\\___/ |___|___/ |___/  \n"; \
	 printf "                                    \n"; \
	 printf "      $(UNDER)$(BOLD)$(CYAN)Made by:\n$(RESET) 	   $(UNDER)$(BOLD)$(CYAN)Fbiondo and Rdolzi\n$(RESET)"


all: $(NAME)

clean:
	@($(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1)
	${RM} ${OBJS}
	${RM} -r ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re