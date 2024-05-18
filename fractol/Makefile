
CC = gcc
HEADER_NAME = fractol.h
LIBMLX_NAME = libmlx.a
NAME = fractol

CFLAGS = -MMD -Wall -Wextra -Werror

LIBMLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER_DIR = inc/
LIBMLX_DIR = minilibx_macos/

INCLUDES = -I $(HEADER_DIR) -I $(LIBMLX_DIR)
LIB_INCLUDE = -L $(LIBMLX_DIR)

LIBMLX_PATH = $(addprefix $(LIBMLX_DIR), $(LIBMLX_NAME))

SRC_FILES = main.c \
			utils.c \
			init.c \
			render.c \
			events.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

DEP_FILES = $(SRC_FILES:.c=.d)

all:
	$(MAKE) -C $(LIBMLX_DIR)
	$(MAKE) $(NAME)

$(NAME): $(OBJ_FILES) $(LIBMLX_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) -o $@ $(LIB_INCLUDE) $(LIBMLX_FLAGS)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEP_FILES)

clean:
	rm -f $(OBJ_FILES) $(DEP_FILES)
	$(MAKE) -C $(LIBMLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBMLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
