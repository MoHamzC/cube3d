#include "cube3d.h"
#include <math.h>

static void	clear_image(mlx_image_t *img)
{
	int	i;
	int	total;

	total = img->width * img->height;
	i = 0;
	while (i < total)
	{
		((int *)img->pixels)[i] = 0;
		i++;
	}
}

static void	compute_floor_row(t_game *game, int y, t_floor_dir *fdir,
	t_floor *fl)
{
	int		p;
	double	pos_z;

	p = y - SCREEN_HEIGHT / 2;
	pos_z = 0.5 * SCREEN_HEIGHT;
	fl->row_distance = pos_z / (double)p;
	fl->floor_step_x = fl->row_distance * (fdir->right_x - fdir->left_x)
		/ SCREEN_WIDTH;
	fl->floor_step_y = fl->row_distance * (fdir->right_y - fdir->left_y)
		/ SCREEN_WIDTH;
	fl->floor_x = game->pos_x + fl->row_distance * fdir->left_x;
	fl->floor_y = game->pos_y + fl->row_distance * fdir->left_y;
}

static void	draw_floor_row(t_game *game, int y, mlx_texture_t *floor_tex,
		t_floor *fl)
{
	int	x;
	int	tx;
	int	ty;
	int	color;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		tx = (int)(floor_tex->width
				* (fl->floor_x - (double)((int)fl->floor_x)))
			& (floor_tex->width - 1);
		ty = (int)(floor_tex->height
				* (fl->floor_y - (double)((int)fl->floor_y)))
			& (floor_tex->height - 1);
		color = ((int *)floor_tex->pixels)[ty * floor_tex->width + tx];
		mlx_put_pixel(game->img, x, y, color);
		fl->floor_x += fl->floor_step_x;
		fl->floor_y += fl->floor_step_y;
		x++;
	}
}

static void	draw_floor_texture(t_game *game, mlx_texture_t *floor_tex)
{
	t_floor_dir	fdir;
	int			y;
	t_floor		fl;

	fdir.left_x = game->dir_x - game->plane_x;
	fdir.left_y = game->dir_y - game->plane_y;
	fdir.right_x = game->dir_x + game->plane_x;
	fdir.right_y = game->dir_y + game->plane_y;
	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		compute_floor_row(game, y, &fdir, &fl);
		draw_floor_row(game, y, floor_tex, &fl);
		y++;
	}
}

static void	draw_textured_column(t_game *game, int x, t_column *col,
		mlx_texture_t *tex)
{
	t_tex_draw	d;

	if (game->ray.side == 0)
		d.tex_x = (int)(((game->pos_y + game->ray.perp_wall_dist
						* game->ray.ray_dir_y)
					- floor(game->pos_y + game->ray.perp_wall_dist
						* game->ray.ray_dir_y)) * tex->width);
	else
		d.tex_x = (int)(((game->pos_x + game->ray.perp_wall_dist
						* game->ray.ray_dir_x)
					- floor(game->pos_x + game->ray.perp_wall_dist
						* game->ray.ray_dir_x)) * tex->width);
	d.step = (double)tex->height / (double)game->ray.line_height;
	d.tex_pos = (col->start - SCREEN_HEIGHT / 2
			+ game->ray.line_height / 2) * d.step;
	d.y = col->start;
	while (d.y < col->end)
	{
		mlx_put_pixel(game->img, x, d.y, ((int *)tex->pixels)[
			tex->width * (((int)d.tex_pos) % tex->height) + d.tex_x]);
		d.tex_pos += d.step;
		d.y++;
	}
}

void	draw_scene(t_game *game)
{
	int						x;
	t_column				col;
	static mlx_texture_t	*wall_texture = NULL;
	static mlx_texture_t	*floor_texture = NULL;

	if (!wall_texture)
		wall_texture = load_texture(game->mlx, "textures/wall.xpm42");
	if (!floor_texture)
		floor_texture = load_texture(game->mlx, "textures/floor.xpm42");
	clear_image(game->img);
	draw_floor_texture(game, floor_texture);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cast_rays(game, &col.start, &col.end, x);
		draw_textured_column(game, x, &col, wall_texture);
		x++;
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
