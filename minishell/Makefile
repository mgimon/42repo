NAME        = minishell
HEADER      = minishell.h
FLAGS       = -Wall -Werror -Wextra -g -fsanitize=address -fsanitize=leak
LIB_DIR     = ./libft/
LIB_NAME    = libft.a
LIB         = $(addprefix $(LIB_DIR), $(LIB_NAME))

SRCS        = main.c executor/executor.c tools/prints.c \
				utils/utils_1.c executor/sections.c utils/utils_2.c \
				utils/utils_3.c executor/builtins_1.c tools/frees.c tools/frees_2.c \
				executor/builtins_2.c utils/utils_4.c tokenizer/token_1.c \
				utils/utils_5.c utils/utils_executor.c \
				utils/utils_6.c utils/utils_7.c utils/utils_8.c \
				utils/utils_9.c utils/utils_10.c utils/utils_11.c \
				utils/utils_12.c utils/utils_13.c utils/utils_14.c \
				utils/utils_15.c utils/utils_16.c utils/utils_17.c \
				utils/utils_18.c utils/utils_19.c utils/utils_20.c \
				utils/utils_21.c utils/utils_22.c \
				tokenizer/trolitoa.c tokenizer/tokenize_aux_1.c  tokenizer/trol_alloc.c\
				tokenizer/tokenize_aux_2.c tokenizer/tokenize_aux_3.c tokenizer/tokenize_aux_4.c\
				tokenizer/tokenize_aux_5.c tokenizer/tokenize_aux_6.c tokenizer/tokenize_aux_7.c\
				tokenizer/tokenize_aux_8.c tokenizer/tokenize_aux_9.c tokenizer/aux_expansor.c\
				tokenizer/aux_aux_expansor.c tokenizer/syntax.c tokenizer/aux_sintax.c tokenizer/extract_token.c\
				tokenizer/extract_token_aux.c tokenizer/extract_token_aux_aux.c tokenizer/extract_section.c\
				tokenizer/extract_section_aux.c tokenizer/extract_section_aux_aux.c tokenizer/extract_section_aux_aux_aux.c\
				tokenizer/extract_section_aux_aux_aux_aux.c \
				utils/utils_23.c utils/utils_24.c utils/utils_25.c utils/utils_26.c utils/utils_27.c \


OBJS        = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) -lft -lreadline

$(LIB):
	@make -C $(LIB_DIR)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all
