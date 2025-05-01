/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:29:52 by mochamsa          #+#    #+#             */
/*   Updated: 2025/05/01 02:20:47 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	window_resize(int width, int height, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->win_width = width;
	game->win_height = height;
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, width, height);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	draw_scene(game);
}

void	free_everything(t_game *game, t_info *info)
{
	if (game->tex_n)
		free_texture(game->tex_n);
	if (game->tex_s)
		free_texture(game->tex_s);
	if (game->tex_e)
		free_texture(game->tex_e);
	if (game->tex_w)
		free_texture(game->tex_w);
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (info)
	{
		free_resources(info);
		free_map(info->map);
	}
	printf("Error: %s\n", "wrong texture");
	exit(1);
}

int	init_game(t_game *game, t_info *info)
{
	game->move_speed = 0.05;
	game->rot_speed = 0.03;
	game->win_width = 800;
	game->win_height = 600;
	game->floor_color = info->floor.hex;
	game->ceiling_color = info->ceiling.hex;
	game->mlx = mlx_init(game->win_width, game->win_height, "cub3D", true);
	game->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	game->tex_n = mlx_load_png(info->texture.north);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	if (game->tex_n == NULL)
		return (free_everything(game, info), 1);
	game->tex_s = mlx_load_png(info->texture.south);
	if (game->tex_s == NULL)
		return (free_everything(game, info), 1);
	game->tex_e = mlx_load_png(info->texture.east);
	if (game->tex_e == NULL)
		return (free_everything(game, info), 1);
	game->tex_w = mlx_load_png(info->texture.west);
	if (game->tex_w == NULL)
		return (free_everything(game, info), 1);
	return (0);
}
