#include "cube3d.h"

static void	draw_vertical_line(mlx_image_t *img, int x, int draw_start,
		int draw_end, int color)
{
	int	y;

    y = draw_start;
	while (y < draw_end)
	{
		mlx_put_pixel(img, x, y, color);
		y++;
    }
}
void	draw_scene(t_game *game)
{
	int	x;
	int	draw_start;
	int	draw_end;
	int	color;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cast_rays(game, &draw_start, &draw_end, x);
		/* Couleur du mur (ici vert) */
		color = 0x00FF00;
		draw_vertical_line(game->img, x, draw_start, draw_end, color);
		/* Plafond (ici bleu) */
		draw_vertical_line(game->img, x, 0, draw_start, 0x0000FF);
		/* Sol (ici marron) */
		draw_vertical_line(game->img, x, draw_end, SCREEN_HEIGHT, 0x654321);
		x++;
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}