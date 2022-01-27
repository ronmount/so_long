NAME = so_long

CC = gcc ${CFLAGS}
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
src/get_next_line.c \
src/get_next_line_utils.c \
src/map_parser.c \
src/utils.c \
src/error_manager.c \
src/draw_everything.c \
src/init_everything.c \
src/parser_stuff.c

MLX = libmlx.dylib
MLX_PATH = mlx


OBJS =		$(SRC:.c=.o)
RM =	rm -f

%.o: %.c so_long.h
	@$(CC) -I$(MLX_PATH) -c $< -o $@

all:	$(NAME)

$(NAME): 	$(OBJS) $(MLX)
			@$(CC) -L$(MLX_PATH) -lmlx -framework Metal -framework AppKit $(OBJS) -o $(NAME)
			@echo "job is done!"

$(MLX):
		@make -C $(MLX_PATH)/
		@cp $(MLX_PATH)/libmlx.dylib libmlx.dylib

clean:
	@$(RM) $(OBJS) $(MLX)
	@make clean -C $(MLX_PATH)
	@make clean -f Makefile_bonus
	@echo "clean is done!"


fclean: clean
		@$(RM) $(NAME)
		@make fclean -f Makefile_bonus
		@echo "full clean is done!"

re: 	fclean all

bonus:
		make -f Makefile_bonus

.PHONY: $(MLX) clean fclean re all $(NAME)
