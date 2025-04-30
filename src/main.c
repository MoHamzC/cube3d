/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:36:56 by mochamsa          #+#    #+#             */
/*   Updated: 2025/05/01 01:48:30 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parsing.h"

int	count_map_lines(char **file_lines, int start)
{
	int	count;

	count = 0;
	while (file_lines[start + count])
		count++;
	return (count);
}

int	extract_map_from_file(char **file_lines, t_info *info)
{
	int	start;
	int	count;
	int	i;

	start = 0;
	while (file_lines[start] && (is_line_empty(file_lines[start])
			|| is_color(file_lines[start]) || is_txt(file_lines[start])))
		start++;
	if (!file_lines[start])
		return (0);
	count = count_map_lines(file_lines, start);
	info->map = malloc(sizeof(char *) * (count + 1));
	if (!info->map)
		return (0);
	i = 0;
	while (i < count)
	{
		info->map[i] = ft_strdup(file_lines[start + i]);
		if (!info->map[i])
			return (0);
		i++;
	}
	info->map[i] = NULL;
	return (1);
}

void	init_info_and_file(t_info *info, char ***file, int ac, char **av)
{
	int	fd;

	if (check_args(ac, av))
		exit(1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_error(NULL, NULL, "Opening file failed");
	*file = get_file(fd);
	close(fd);
	if (!*file)
		exit_error(NULL, NULL, "Could not read file");
	if (!parse_file(*file, info))
		exit_error(info, *file, NULL);
	if (!extract_map_from_file(*file, info))
		exit_error(info, *file, "Extracting map failed");
	remove_newlines_from_map(info->map);
	if (!valid_map(info->map, info))
		exit_error(info, *file, NULL);
}

void	parse_and_init_game(t_game *game, t_info *info, char **file)
{
	game->map = info->map;
	if (init_game(game, info) != 0)
		exit_error(info, file, "Game initialization failed");
	set_player_start(game);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_info	info;
	char	**file;

	ft_memset(&game, 0, sizeof(t_game));
	init_info_and_file(&info, &file, ac, av);
	parse_and_init_game(&game, &info, file);
	draw_scene(&game);
	mlx_resize_hook(game.mlx, window_resize, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	free_resources(&info);
	free_map(file);
	free_game(&game);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_game	game;
// 	t_info	info;
// 	char	**file;
// 	int		fd;

// 	if (check_args(ac, av))
// 		return (1);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd == -1)
// 		exit_error(NULL, NULL, "Opening file failed");
// 	file = get_file(fd);
// 	close(fd);
// 	if (!file)
// 		exit_error(NULL, NULL, "Could not read file");
// 	if (!parse_file(file, &info))
// 		exit_error(&info, file, NULL);
// 	if (!extract_map_from_file(file, &info))
// 		exit_error(&info, file, "Extracting map failed");
// 	remove_newlines_from_map(info.map);
// 	if (!valid_map(info.map, &info))
// 		exit_error(&info, file, NULL);
// 	if (init_game(&game, &info) != 0)
// 		exit_error(&info, file, "Game initialization failed");
// 	game.map = info.map;
// 	set_player_start(&game);
// 	draw_scene(&game);
// 	mlx_resize_hook(game.mlx, window_resize, &game);
// 	mlx_loop_hook(game.mlx, update, &game);
// 	mlx_loop(game.mlx);
// 	free_resources(&info);
// 	free_map(file);
// 	free_game(&game);
// 	return (0);
// }
