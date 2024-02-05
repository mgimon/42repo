NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

HEAD		= libft.h

SRCS		= ft_memset.c \
			  ft_bzero.c \
			  ft_strlen.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strnstr.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_atoi.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_itoa.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_split.c \

BSRCS		= ft_lstnew_bonus.c \
			  ft_lstadd_front_bonus.c \
			  ft_lstsize_bonus.c \
			  ft_lstlast_bonus.c \
			  ft_lstadd_back_bonus.c \
			  ft_lstdelone_bonus.c \
			  ft_lstclear_bonus.c \
			  ft_lstiter_bonus.c \
			  ft_lstmap_bonus.c \

OBJS		= ${SRCS:.c=.o}

BOBJS		= ${BSRCS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} 
			@ar rc ${NAME} ${OBJS}

%.o : %.c ${HEAD} Makefile
			${CC} ${CFLAGS} -c $<

bonus:		${NAME} ${BOBJS} 
			@ar rc ${NAME} ${BOBJS}

clean:
			@rm -f ${OBJS} ${BOBJS}

fclean:		clean
			@rm -f ${NAME}

re: 		fclean all

# output: 	${NAME} main.c
# 			@${CC} ${CFLAGS} main.c ${NAME} -o output

# sclean:		fclean
# 			@rm -f output
# 			rm	-rf *.out

.PHONY:		all clean fclean re #sclean output
#incluye todas las referencias que no quiere que compruebes
