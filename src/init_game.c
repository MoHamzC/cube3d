#include "cube3d.h"

int	init_game(t_game *game)
{
	game->pos_x = 3.5;
	game->pos_y = 3.5;
	game->dir_x = -1.0;
	game->dir_y = 0.0;
	game->plane_x = 0.0;
	game->plane_y = 0.66;
	game->move_speed = 0.1;
	game->rot_speed = 0.1;
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cube3D", false);
	if (!game->mlx)
	{
		printf("Erreur d'initialisation MLX42\n");
		return (1);
	}
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
	{
		printf("Erreur de création d'image\n");
		return (1);
	}
	return (0);
}
