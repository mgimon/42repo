NAME = push_swap

SRCS = main.c \
		algorithm.c costs.c median_sort_push.c \
		nodes.c push.c \
		reverse.c rotate.c small_stack_sorting.c swap.c \
		targets.c utils.c 

INCLUDE = ./push_swap.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS} $(INCLUDE)
	@${CC} ${SRCS} -o ${NAME}

clean:
			@${RM} ${OBJS}

fclean: 
			@${RM} ${OBJS}
			@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
