#include "cube3d.h"
#include <stdio.h>

void	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		rotate_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		rotate_right(game);
	draw_scene(game);
}
