NAME = cube3d

SRCS =	src/main.c \
		src/init_game.c \
		src/free_game.c \
		src/graphics/raycasting.c \
		src/graphics/draw_scene.c \
		src/graphics/textures.c \
		src/movements.c \
		src/update.c \
		src/set_orientation.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I../mlx/include
MLXFLAGS = -L../mlx/build -lmlx42 -lXext -lX11 -lm -lglfw

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re