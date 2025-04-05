#include "cube3d.h"
#include <stdio.h>

void	update(void *param)
{
	t_game	*game;
    
	game = (t_game *)param;
	/* Vérifie si la touche ESC est enfoncée pour quitter */
	printf("Position: x = %f, y = %f\n", game->pos_x, game->pos_y);
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	/* Mouvement continu selon les touches enfoncées */
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
    {
        printf("W pressed\n");
		move_forward(game);
    }
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		rotate_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		rotate_right(game);
	/* Redessine la scène avec la nouvelle position */
	draw_scene(game);
}