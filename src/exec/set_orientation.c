/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_orientation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochamsa <mochamsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:33:58 by mochamsa          #+#    #+#             */
/*   Updated: 2025/04/07 20:52:11 by mochamsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_orientation_ns(t_game *game, char c)
{
	if (c == 'N')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (c == 'S')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
}

void	set_orientation_ew(t_game *game, char c)
{
	if (c == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	else if (c == 'W')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

void	set_orientation(t_game *game, char c)
{
	if (c == 'N' || c == 'S')
		set_orientation_ns(game, c);
	else if (c == 'E' || c == 'W')
		set_orientation_ew(game, c);
	else
	{
		game->dir_x = 0;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0;
	}
}

void	set_player_start(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'N'
				|| game->map[i][j] == 'S'
				|| game->map[i][j] == 'E'
				|| game->map[i][j] == 'W')
			{
				game->pos_x = j + 0.5;
				game->pos_y = i + 0.5;
				set_orientation(game, game->map[i][j]);
				return ;
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
