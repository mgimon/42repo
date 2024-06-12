
NAME        := pipex
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g

SRCS        :=      ft_printf/ft_printf.c \
                          ft_printf/print_char.c \
                          ft_printf/print_hex.c \
                          ft_printf/print_integer.c \
                          ft_printf/print_percent.c \
                          ft_printf/print_pointer.c \
                          ft_printf/print_string.c \
                          ft_printf/print_unsigned.c \
                          ft_printf/libft/ft_itoa.c \
                          ft_printf/libft/ft_atoi.c \
                          ft_printf/libft/ft_bzero.c \
                          ft_printf/libft/ft_calloc.c \
                          ft_printf/libft/ft_isalnum.c \
                          ft_printf/libft/ft_isalpha.c \
                          ft_printf/libft/ft_isascii.c \
                          ft_printf/libft/ft_isdigit.c \
                          ft_printf/libft/ft_isprint.c \
                          ft_printf/libft/ft_lstadd_back_bonus.c \
                          ft_printf/libft/ft_lstadd_front_bonus.c \
                          ft_printf/libft/ft_lstclear_bonus.c \
                          ft_printf/libft/ft_lstdelone_bonus.c \
                          ft_printf/libft/ft_lstiter_bonus.c \
                          ft_printf/libft/ft_lstlast_bonus.c \
                          ft_printf/libft/ft_lstmap_bonus.c \
                          ft_printf/libft/ft_lstnew_bonus.c \
                          ft_printf/libft/ft_lstsize_bonus.c \
                          ft_printf/libft/ft_memchr.c \
                          ft_printf/libft/ft_memcmp.c \
                          ft_printf/libft/ft_memcpy.c \
                          ft_printf/libft/ft_memmove.c \
                          ft_printf/libft/ft_memset.c \
                          ft_printf/libft/ft_putchar_fd.c \
                          ft_printf/libft/ft_putendl_fd.c \
                          ft_printf/libft/ft_putnbr_fd.c \
                          ft_printf/libft/ft_putstr_fd.c \
                          ft_printf/libft/ft_strchr.c \
                          ft_printf/libft/ft_strdup.c \
                          ft_printf/libft/ft_striteri.c \
                          ft_printf/libft/ft_strjoin.c \
                          ft_printf/libft/ft_strlcat.c \
                          ft_printf/libft/ft_strlcpy.c \
                          ft_printf/libft/ft_strlen.c \
                          ft_printf/libft/ft_strmapi.c \
                          ft_printf/libft/ft_strncmp.c \
                          ft_printf/libft/ft_strnstr.c \
                          ft_printf/libft/ft_strrchr.c \
                          ft_printf/libft/ft_substr.c \
                          ft_printf/libft/ft_tolower.c \
                          ft_printf/libft/ft_toupper.c \
                          ft_printf/libft/ft_strtrim.c \
                          ft_printf/libft/ft_split.c \
                          prints.c \
                          utils.c \
                          main.c \
                          process.c \
                          init.c \
                          utils_two.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


