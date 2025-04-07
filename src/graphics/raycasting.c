/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochamsa <mochamsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:54:02 by mochamsa          #+#    #+#             */
/*   Updated: 2025/04/07 20:54:03 by mochamsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

static void	init_ray(t_game *game, int x, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)game->win_width - 1;
	ray->ray_dir_x = game->dir_x + game->plane_x * ray->camera_x;
	ray->ray_dir_y = game->dir_y + game->plane_y * ray->camera_x;
	ray->map_x = (int)game->pos_x;
	ray->map_y = (int)game->pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	init_steps(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->pos_y) * ray->delta_dist_y;
	}
}

static void	perform_dda(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

void	cast_rays(t_game *game, int *draw_start, int *draw_end, int x)
{
	t_ray	ray;

	init_ray(game, x, &ray);
	init_steps(game, &ray);
	perform_dda(game, &ray);
	if (ray.side == 0)
		ray.perp_wall_dist = (ray.map_x - game->pos_x
				+ (1 - ray.step_x) / 2.0) / ray.ray_dir_x;
	else
		ray.perp_wall_dist = (ray.map_y - game->pos_y
				+ (1 - ray.step_y) / 2.0) / ray.ray_dir_y;
	ray.line_height = (int)(game->win_height / ray.perp_wall_dist);
	*draw_start = -ray.line_height / 2 + game->win_height / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = ray.line_height / 2 + game->win_height / 2;
	if (*draw_end >= game->win_height)
		*draw_end = game->win_height - 1;
	game->ray = ray;
}
