#include "cube3d.h"
#include <math.h>

/*
** move_forward :
** Calcule la nouvelle position en avant et vérifie que le joueur ne rentre pas
** dans un mur ('1') en se déplaçant sur l'axe X et sur l'axe Y.
*/
void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x + game->dir_x * game->move_speed;
	new_y = game->pos_y + game->dir_y * game->move_speed;
	/* Vérification sur l'axe X : on teste la colonne correspondant à la nouvelle position */
	if (game->map[(int)game->pos_y][(int)new_x] != '1')
		game->pos_x = new_x;
	/* Vérification sur l'axe Y : on teste la ligne correspondant à la nouvelle position */
	if (game->map[(int)new_y][(int)game->pos_x] != '1')
		game->pos_y = new_y;
}

/*
** move_backward :
** Calcule la nouvelle position en arrière et vérifie la présence d'obstacles.
*/
void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x - game->dir_x * game->move_speed;
	new_y = game->pos_y - game->dir_y * game->move_speed;
	if (game->map[(int)game->pos_y][(int)new_x] != '1')
		game->pos_x = new_x;
	if (game->map[(int)new_y][(int)game->pos_x] != '1')
		game->pos_y = new_y;
}

/*
** rotate_left :
** Effectue une rotation vers la gauche en mettant à jour les vecteurs
** de direction et le plan de caméra.
*/
void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(game->rot_speed) - game->dir_y * sin(game->rot_speed);
	game->dir_y = old_dir_x * sin(game->rot_speed) + game->dir_y * cos(game->rot_speed);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(game->rot_speed) - game->plane_y * sin(game->rot_speed);
	game->plane_y = old_plane_x * sin(game->rot_speed) + game->plane_y * cos(game->rot_speed);
}

/*
** rotate_right :
** Effectue une rotation vers la droite en mettant à jour les vecteurs.
*/
void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-game->rot_speed) - game->dir_y * sin(-game->rot_speed);
	game->dir_y = old_dir_x * sin(-game->rot_speed) + game->dir_y * cos(-game->rot_speed);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(-game->rot_speed) - game->plane_y * sin(-game->rot_speed);
	game->plane_y = old_plane_x * sin(-game->rot_speed) + game->plane_y * cos(-game->rot_speed);
}
