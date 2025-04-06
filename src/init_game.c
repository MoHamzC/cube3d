#include "cube3d.h"

int	init_game(t_game *game, t_info *info)
{
	game->move_speed = 0.05;
	game->rot_speed = 0.03;
	game->floor_color = info->floor.hex;
	game->ceiling_color = info->ceiling.hex;
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", true);
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->tex_n = load_texture(game->mlx, info->texture.north);
	if (game->tex_n == NULL)
		return (mlx_close_window(game->mlx),1);
	game->tex_s = load_texture(game->mlx, info->texture.south);
	if (game->tex_s == NULL)
		return (mlx_close_window(game->mlx),1);
	game->tex_e = load_texture(game->mlx, info->texture.east);
	if (game->tex_e == NULL)
		return (mlx_close_window(game->mlx),1);
	game->tex_w = load_texture(game->mlx, info->texture.west);
	if (game->tex_w == NULL)	
		return (mlx_close_window(game->mlx),1);
	return (0);
}
