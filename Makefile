NAME = cub3d

SRCS = main.c minicheck.c
LBFT = $(wildcard libft/*.c)
GNL   =  $(wildcard getnextline/*.c)
PARSER = $(wildcard parser/*.c)

FLAGS = -Wextra -Werror -Wall

CC = gcc ${FLAGS}
RM = rm -f
OS = $(shell uname)
OBJS = ${SRCS:.c=.o} ${GNL:.c=.o} ${PARSER:.c=.o} ${LBFT:.c=.o} 

%.o: %.c
	@if [ $(OS) = "Darwin" ]; then \
		$(CC) -g -Imlx -O3 -I ./cub3d.h  -c $< -o $@;\
    else \
		$(CC) -g -I/usr/include -Imlx_linux -I ./cub3d.h -c $< -o $@;\
    fi
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "$(BOLD)$(GREEN)\r%100s\r[%d/%d] 😊(%d%%) $(END)$(BOLD)$(BLUE)$<" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)

RED		=	\033[31m
GREEN	=	\033[32m
BLUE	=	\033[34m
CYAN	=	\033[36m
BOLD	=	\033[1m
UNDER	=	\033[4m
END		=	\033[0m
RESET	= \033[0;0m

SRC_COUNT     = 0
SRC_COUNT_TOT = $(words $(LBFT) + $(GNL) + $(PARSER))
SRC_PCT       = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
		
$(NAME): $(OBJS)
	@printf "$(UNDER)$(BOLD)$(CYAN)\nCompiling CUB3D\n$(RESET)$(BOLD)"
	@if [ $(OS) = "Darwin" ]; then\
		make mac;\
	else\
		make linux;\
	fi

mac: 
	@make -C mlx 1>/dev/null 2>&1 
	@$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

linux:
	@make -C mlx_linux 2> /dev/null &&  cp ./mlx_linux/libmlx.a ./ 
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME);\

all: $(NAME)

clean:
	@${RM} ${OBJS}
	@if [ $(OS) = "Darwin" ]; then\
		cd mlx && make clean && cd .. ;\
	else\
		cd mlx_linux && make clean && cd .. ;\
	fi

fclean: clean
	@${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re

push: fclean
	@read -p "Enter comment for git push:" comment;\
	git add .  ;\
    git commit -m "$$comment"  ;\
	git push \
 	
status:
	git status