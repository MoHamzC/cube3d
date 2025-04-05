#ifndef CUBE3D_H
# define CUBE3D_H

# include <MLX42/MLX42.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
}				t_ray;

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
	t_ray		ray;
}				t_game;

typedef struct s_tex_draw
{
	int		y;
	int		tex_x;
	double	step;
	double	tex_pos;
}				t_tex_draw;

typedef struct s_column
{
	int	start;
	int	end;
}	t_column;

typedef struct s_floor
{
	double	row_distance;
	double	floor_step_x;
	double	floor_step_y;
	double	floor_x;
	double	floor_y;
}				t_floor;

typedef struct s_floor_dir
{
	double	left_x;
	double	left_y;
	double	right_x;
	double	right_y;
}				t_floor_dir;

/* Prototypes */
int				init_game(t_game *game);
void			free_game(t_game *game);
void			draw_scene(t_game *game);
void			cast_rays(t_game *game, int *draw_start, int *draw_end, int x);
char			**parse_cub(const char *filename);
mlx_texture_t	*load_texture(mlx_t *mlx, char *path);
void			free_texture(mlx_texture_t *texture);
void			update(void *param);
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);
void			key_handler(mlx_key_data_t keydata, void *param);

#endif