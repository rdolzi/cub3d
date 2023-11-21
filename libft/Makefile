# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 11:21:42 by fbiondo           #+#    #+#              #
#    Updated: 2023/10/18 17:36:54 by flaviobiond      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_isprint.c ft_atoi.c ft_tolower.c ft_strlen.c ft_toupper.c ft_memchr.c ft_isalnum.c ft_memcmp.c ft_strncmp.c ft_isalpha.c ft_memcpy.c \
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strrchr.c ft_strlcpy.c ft_strlcat.c ft_itoa.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_substr.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_itoa.c ft_strmapi.c ft_realloc.c\

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
