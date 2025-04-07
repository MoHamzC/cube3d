#include "cube3d.h"
#include <math.h>

static void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	color = game->ceiling_color;

	y = 0;
	while (y < game->win_height / 2)
	{
		x = 0;
		while (x < game->win_width)
		{
			mlx_put_pixel(game->img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_game *game)
{
	int	x;
	int	y;
	int	color = game->floor_color;

	y = game->win_height / 2;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			mlx_put_pixel(game->img, x, y, color);
			x++;
		}
		y++;
	}
}
mlx_texture_t	*select_wall_texture(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x > 0)
			return (game->tex_e);
		else
			return (game->tex_w);
	}
	else
	{
		if (game->ray.ray_dir_y > 0)
			return (game->tex_s);
		else
			return (game->tex_n);
	}
}

static void	draw_textured_column(t_game *game, int x, t_column *col,
		mlx_texture_t *tex)
{
	t_tex_draw d;
	double	wall_x;

	if (game->ray.side == 0)
		wall_x = game->pos_y + game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		wall_x = game->pos_x + game->ray.perp_wall_dist * game->ray.ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	d.tex_x = (int)(wall_x * tex->width);
	if ((game->ray.side == 0 && game->ray.ray_dir_x > 0)
		|| (game->ray.side == 1 && game->ray.ray_dir_y < 0))
		d.tex_x = tex->width - d.tex_x - 1;
	d.step = (double)tex->height / (double)game->ray.line_height;
	d.tex_pos = (col->start - game->win_height / 2 + game->ray.line_height / 2)
		* d.step;
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
	int		x;
	t_column	col;

	draw_ceiling(game);
	draw_floor(game);
	x = 0;
	while (x < game->win_width)
	{
		cast_rays(game, &col.start, &col.end, x);
		draw_textured_column(game, x, &col, select_wall_texture(game));
		x++;
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
