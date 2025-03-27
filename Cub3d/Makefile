NAME = cub3d

SRC = src/pieromain.c src/map.c src/utils.c src/errors.c src/debug.c src/free.c \
		 src/main.c src/raycasting.c src/actions.c src/data_init.c

CC = gcc
CCFLAGS = -Wall -Werror -Wextra -g
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# -L/usr/X11/lib -lX11 -lXext -lm "ON MAC"...... and also without $(X11_LIBS) in line 31
# gcc -Wall -Wextra -Werror -g so_long.c -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11  "ON MY LAPTOP"

LIBFT = ./libft_full/libft.a
LIBFT_PATH = ./libft_full
MLX_DIR = ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a

X11_LIBS = -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

$(NAME):
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_PATH)
	$(CC) $(CCFLAGS) $(MLX_FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MLX) $(X11_LIBS) -lm

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) map/valid.ber

re : fclean all

# gcc so_long.c -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
# valgrind --leak-check=full --show-leak-kinds=all

