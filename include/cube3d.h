#ifndef CUBE3D_H
# define CUBE3D_H

# include <MLX42/MLX42.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

typedef struct s_game
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	/* Ajoutez ici d'autres éléments si nécessaire (textures, etc.) */
}				t_game;

/* Initialisation et libération */
int		init_game(t_game *game);
void	free_game(t_game *game);

/* Affichage et raycasting */
void	draw_scene(t_game *game);
void	cast_rays(t_game *game, int *draw_start, int *draw_end, int x);

/* Parsing de la map (.cub) */
char	**parse_cub(const char *filename);

/* Gestion des textures */
mlx_texture_t	*load_texture(mlx_t *mlx, char *path);
void			free_texture(mlx_texture_t *texture);

/* Gestion des événements et mouvements */
void	update(void *param);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

#endif