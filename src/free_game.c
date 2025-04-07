/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochamsa <mochamsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:29:42 by mochamsa          #+#    #+#             */
/*   Updated: 2025/04/07 20:29:42 by mochamsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_game(t_game *game)
{
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->tex_n)
		free_texture(game->tex_n);
	if (game->tex_s)
		free_texture(game->tex_s);
	if (game->tex_e)
		free_texture(game->tex_e);
	if (game->tex_w)
		free_texture(game->tex_w);
	if (game->mlx)
		mlx_terminate(game->mlx);
}
