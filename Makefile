NAME = cub3d

SRCS = main.c minicheck.c
LBFT = $(wildcard libft/*.c)
GNL   =  $(wildcard getnextline/*.c)
PARSER = $(wildcard parser/*.c)

FLAGS = -Wextra -Werror -Wall

CC = gcc ${FLAGS}
RM = rm -f

OBJS = ${SRCS:.c=.o} ${GNL:.c=.o} ${PARSER:.c=.o} ${LBFT:.c=.o} 


RED		=	\033[31m
GREEN	=	\033[32m
BLUE	=	\033[34m
CYAN	=	\033[36m
BOLD	=	\033[1m
UNDER	=	\033[4m
END		=	\033[0m
RESET	= \033[0;0m

SRC_COUNT     = 0
SRC_COUNT_TOT = 34
SRC_PCT       = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

%.o: %.c
	$(CC) -Imlx -g -c $< -o ${<:.c=.o}
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "$(BOLD)$(GREEN)\r%100s\r[%d/%d] 😊(%d%%) $(END)$(BOLD)$(BLUE)$<" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)

		
$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "$(UNDER)$(BOLD)$(CYAN)\nCompiling CUB3D\n$(RESET)$(BOLD)"

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re