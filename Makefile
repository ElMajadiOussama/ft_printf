NAME = libft.a

SRCS = ft_putchar.c ft_putnbr.c ft_strlen.c ft_printf.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror 
CC = gcc
RM = rm -f

all: ${NAME}

${NAME} :   ${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re