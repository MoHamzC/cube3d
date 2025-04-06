#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	*test_map[] = {
		"1111111",
		"1001001",
		"1000001",
		"110E011",
		"1000001",
		"1001001",
		"1111111",
		NULL
	};

	if (argc != 2)
	{
		printf("Usage: %s <map_file.cub>\n", argv[0]);
		return (1);
	}
	game.map = test_map;
	game.move_speed = 0.05;
	game.rot_speed = 0.03;
	game.floor_color = 0x303030;   /* Gris foncé */
	game.ceiling_color = 0x87CEEB; /* Bleu ciel */
	if (init_game(&game) != 0)
		return (1);
	set_player_start(&game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
