NAME = cub3d

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
MLX_DIR = mlx
MLX_MAKE = $(MLX_DIR)/Makefile

OBJS = ${SRCS:.c=.o} ${GNL:%.c=%.o} ${BUILDER:%.c=%.o} ${CHECKER:%.c=%.o} ${ENGINE:%.c=%.o} ${INITIALIZER:%.c=%.o} ${RAYCASTER:%.c=%.o} ${UTILS:%.c=%.o}


RED		=	\033[31m
GREEN	=	\033[32m
BLUE	=	\033[34m
CYAN	=	\033[36m
BOLD	=	\033[1m
UNDER	=	\033[4m
END		=	\033[0m
RESET	= \033[0;0m

SRC_COUNT     = 0
SRC_COUNT_TOT = 11
SRC_PCT       = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

%.o: %.c
	@$(CC) -Imlx -g -c $< -o $@
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
	 $(CC) $(OBJS) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME); \
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

fclean: clean
	${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re