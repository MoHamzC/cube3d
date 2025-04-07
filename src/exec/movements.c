/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochamsa <mochamsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:30:14 by mochamsa          #+#    #+#             */
/*   Updated: 2025/04/07 20:33:18 by mochamsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x + game->dir_x * game->move_speed;
	new_y = game->pos_y + game->dir_y * game->move_speed;
	if (game->map[(int)game->pos_y][(int)new_x] != '1')
		game->pos_x = new_x;
	if (game->map[(int)new_y][(int)game->pos_x] != '1')
		game->pos_y = new_y;
}

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

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x - game->plane_x * game->move_speed;
	new_y = game->pos_y - game->plane_y * game->move_speed;
	if (game->map[(int)game->pos_y][(int)new_x] != '1')
		game->pos_x = new_x;
	if (game->map[(int)new_y][(int)game->pos_x] != '1')
		game->pos_y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x + game->plane_x * game->move_speed;
	new_y = game->pos_y + game->plane_y * game->move_speed;
	if (game->map[(int)game->pos_y][(int)new_x] != '1')
		game->pos_x = new_x;
	if (game->map[(int)new_y][(int)game->pos_x] != '1')
		game->pos_y = new_y;
}
