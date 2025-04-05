#include "cube3d.h"
#include <math.h>

/*
** cast_rays :
** Pour une colonne x de l'écran, calcule la position relative du rayon,
** simule la distance au mur et détermine les positions de début et de fin
** du tracé vertical du mur.
*/
void	cast_rays(t_game *game, int *draw_start, int *draw_end, int x)
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	perp_wall_dist;
	int		line_height;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray_dir_x = game->dir_x + game->plane_x * camera_x;
	ray_dir_y = game->dir_y + game->plane_y * camera_x;
	/* Ici, on simule la distance au mur (à remplacer par l'algorithme DDA) */
	perp_wall_dist = 1.0 + fabs(ray_dir_x) * 0.5;
	line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
	*draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (*draw_end >= SCREEN_HEIGHT)
		*draw_end = SCREEN_HEIGHT - 1;
}