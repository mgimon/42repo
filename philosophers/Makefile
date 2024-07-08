SRCS = init.c \
		main.c \
		process.c \
		utils.c \
		utils_2.c \
		tasks.c

OBJS = ${SRCS:.c=.o}
NAME = philo
HEADER = philo.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

%.o:%.c     $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all:        ${NAME}

${NAME}:    ${OBJS}
			$(CC) $(CFLAGS) -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:     clean
			${RM} ${NAME}

re:         fclean all

.PHONY: all clean fclean re

