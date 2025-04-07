/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochamsa <mochamsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:32:08 by mochamsa          #+#    #+#             */
/*   Updated: 2025/04/07 20:33:42 by mochamsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(game->rot_speed) - game->dir_y
		* sin(game->rot_speed);
	game->dir_y = old_dir_x * sin(game->rot_speed) + game->dir_y
		* cos(game->rot_speed);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(game->rot_speed) - game->plane_y
		* sin(game->rot_speed);
	game->plane_y = old_plane_x * sin(game->rot_speed) + game->plane_y
		* cos(game->rot_speed);
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-game->rot_speed) - game->dir_y
		* sin(-game->rot_speed);
	game->dir_y = old_dir_x * sin(-game->rot_speed) + game->dir_y
		* cos(-game->rot_speed);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(-game->rot_speed) - game->plane_y
		* sin(-game->rot_speed);
	game->plane_y = old_plane_x * sin(-game->rot_speed) + game->plane_y
		* cos(-game->rot_speed);
}
