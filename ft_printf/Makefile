NAME		= libftprintf.a

HEADER		= ft_printf.h

FLAGS		= -Wall -Werror -Wextra

AR_FLAGS	= -rcs

LIB_DIR		= ./libft/

LIB_NAME	= libft.a

LIB			= $(addprefix $(LIB_DIR), $(LIB_NAME))

OBJS		= ${SRCS:%.c=%.o}

SRCS		= ft_printf.c print_char.c print_string.c print_percent.c print_integer.c print_pointer.c print_unsigned.c print_hex.c

.PHONY: all clean fclean re 

all: ${NAME}

${NAME}: ${OBJS}
	make -C $(LIB_DIR)
	cp $(LIB) $(NAME)
	ar $(AR_FLAGS) $@ $?

%.o : %.c Makefile $(HEADER)
	cc $(FLAGS) -c $< -o $@

clean:
	@echo "--> Remove *.o files. "
	@make clean -C $(LIB_DIR)
	rm -rf $(OBJS) .lib

fclean: clean
	@echo "--> Remove $(NAME) file"
	@make fclean -C $(LIB_DIR)
	rm -rf $(NAME)

re: fclean all
