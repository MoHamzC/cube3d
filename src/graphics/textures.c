/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:54:08 by mochamsa          #+#    #+#             */
/*   Updated: 2025/05/01 00:14:41 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

uint32_t	get_texture_color(mlx_texture_t *tex, int x, int y)
{
	int	i;

	i = (y * tex->width + x) * 4;
	return (tex->pixels[i + 0] << 24
		| tex->pixels[i + 1] << 16
		| tex->pixels[i + 2] << 8
		| tex->pixels[i + 3]);
}

// mlx_texture_t	*load_texture(mlx_t *mlx, char *path)
// {
// 	mlx_texture_t	*texture;

// 	(void)mlx;
// 	texture = (mlx_texture_t *)mlx_load_xpm42(path);
// 	if (!texture)
// 	{
// 		printf("Error: \n loading texture %s\n", path);
// 		exit(EXIT_FAILURE); //FREEE ICI
// 	}
// 	return (texture);
// }

void	free_texture(mlx_texture_t *texture)
{
	if (texture)
		mlx_delete_texture(texture);
}
