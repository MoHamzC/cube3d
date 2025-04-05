#include "../include/cube3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
    char	*test_map[] = {
	"111111111111",
	"100000000001",
	"100000000001",
	"10N000000001",
	"100000000001",
	"100000000001",
	"100000000001",
	"100000000001",
	"100000000001",
	"100000000001",
	"100000000001",
	"100000000001",
	"111111111111",
	NULL
};
	if (argc != 2)
	{
		printf("Usage: %s <map_file.cub>\n", argv[0]);
		return (1);
	}
	//game.map = parse_cub(argv[1]);
	game.map = test_map;
    if (!game.map)
	{
		printf("Erreur de parsing de la map.\n");
		return (1);
	}
	if (init_game(&game) != 0)
		return (1);
	mlx_loop_hook(game.mlx, update, &game);
	draw_scene(&game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}