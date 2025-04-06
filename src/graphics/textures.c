#include "cube3d.h"

mlx_texture_t	*load_texture(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;

	(void)mlx;
	texture = (mlx_texture_t *)mlx_load_xpm42(path);
	if (!texture)
	{
		printf("Erreur de chargement de la texture: %s\n", path);
		exit(EXIT_FAILURE);
	}
	return (texture);
}

void	free_texture(mlx_texture_t *texture)
{
	if (texture)
		mlx_delete_texture(texture);
}
