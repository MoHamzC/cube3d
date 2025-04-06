#include "cube3d.h"

int	init_game(t_game *game)
{
	game->move_speed = 0.05;
	game->rot_speed = 0.03;
	game->floor_color = 0x303030;
	game->ceiling_color = 0x87CEEB;
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", true);
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->tex_n = load_texture(game->mlx, "textures/north.xpm42");
	if (game->tex_n == NULL)
		return (mlx_close_window(game->mlx),1);
	game->tex_s = load_texture(game->mlx, "textures/south.xpm42");
	if (game->tex_s == NULL)
		return (mlx_close_window(game->mlx),1);
	game->tex_e = load_texture(game->mlx, "textures/east.xpm42");
	if (game->tex_e == NULL)
		return (mlx_close_window(game->mlx),1);
	game->tex_w = load_texture(game->mlx, "textures/west.xpm42");
	if (game->tex_w == NULL)	
		return (mlx_close_window(game->mlx),1);
	return (0);
}
