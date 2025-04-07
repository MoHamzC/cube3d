#include "cube3d.h"
#include "parsing.h"

int check_args(int ac, char *av[])
{
    int len; 

    len = 0; 
    if(ac != 2)
    {
        printf("not good amout of args\n");
        return(1);
    }
    len = ft_strlen(av[1]); 
    if (len < 4 || ft_strncmp(&av[1][len - 4], ".cub", 4) != 0)
	{
		printf("error\nnot a .cub\n");
		return (1);
	}
    return(0); 
}

int	extract_map_from_file(char **file_lines, t_info *info)
{
	int map_start;
	
	
	map_start = 0;
	while (file_lines[map_start])
	{
		printf("%s\"\n", file_lines[map_start]);
		if (!is_line_empty(file_lines[map_start]) &&
			!is_txt(file_lines[map_start]) &&
			!is_color(file_lines[map_start]))
			break;
		map_start++;
	}
	if (!file_lines[map_start])
	{
		fprintf(stderr, "Error\n no map found in the file\n");
		return (0);
	}

	info->map = &file_lines[map_start];
	return (1);
}

void print_map(char **map) //debugging, will be deleted
{
	int i = 0;
	printf("\n:\n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;
	char	**file_lines;
	t_info	info;

	if (check_args(ac, av))
		return (1);

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	file_lines = get_file(fd);
	close(fd);
	if (!file_lines)
	{
		fprintf(stderr, "Error\n could not read map file\n");
		return (1);
	}
	if (!parse_file(file_lines, &info))
	{
		free_map(file_lines);
		free_resources(&info);
		return (1);
	}
	extract_map_from_file(file_lines, &info);
	if (!valid_map(info.map, &info))
	{
		free_resources(&info);
		free_map(file_lines); 
		return (1);
	}
	printf("Map valid!\n");
	print_map(info.map);
	printf("la %s\n",info.texture.north);
	game.map = info.map;
	if (init_game(&game, &info) != 0)
		return (1);
	set_player_start(&game);
	mlx_resize_hook(game.mlx, window_resize, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	free_resources(&info);
	free_map(file_lines);
	free_game(&game);
	return (0);
}
