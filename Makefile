NAME = cube3d

SRCS =	src/main.c \
		src/init_game.c \
		src/free_game.c \
		src/graphics/raycasting.c \
		src/graphics/draw_scene.c \
		src/graphics/textures.c \
		src/movements.c \
		src/rotate.c \
		src/update.c \
		src/set_orientation.c \
		src/parsing/parsing.c \
		src/parsing/parsing_utils.c \
		src/parsing/get_file.c \
		src/parsing/get_stuff.c \
		src/parsing/identify_line.c \
		src/parsing/check_error.c \
		include/libft/ft_atoi.c \
		include/libft/ft_isdigit.c \
		include/libft/ft_split.c \
		include/libft/ft_strchr.c \
		include/libft/ft_strlcpy.c \
		include/libft/ft_strlcat.c \
		include/getnextline/get_next_line.c \
		include/getnextline/get_next_line_utils.c

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
