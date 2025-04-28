/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:36:56 by mochamsa          #+#    #+#             */
/*   Updated: 2025/04/28 23:37:26 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube3d.h"
#include "parsing.h"

int	exit_error(t_info *info, char **file, const char *msg)
{
	if (msg)
		fprintf(stderr, "Error\n%s\n", msg);
	if (file)
		free_map(file);
	if (info)
	{
		if (info->map)
			free_map(info->map);   
		free_resources(info);
	}
	exit(1);
}


int	check_args(int ac, char *av[])
{
	int	len;

	if (ac != 2)
		return (printf("Error: wrong number of arguments\n"), 1);
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(&av[1][len - 4], ".cub", 4) != 0)
		return (printf("Error: not a .cub file\n"), 1);
	return (0);
}

int	extract_map_from_file(char **file_lines, t_info *info)
{
	int	start;
	int	count;
	int	i;

	start = 0;
	while (file_lines[start] && (is_line_empty(file_lines[start]) || is_color(file_lines[start]) || is_txt(file_lines[start])))
		start++;
	if (!file_lines[start])
		return (0);
	count = 0;
	i = start;
	while (file_lines[i])
	{
		count++;
		i++;
	}
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

int	main(int ac, char **av)
{
	t_game	game;
	t_info	info;
	char	**file;
	int		fd;

	if (check_args(ac, av))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_error(NULL, NULL, "Opening file failed");
	file = get_file(fd);
	close(fd);
	if (!file)
		exit_error(NULL, NULL, "Could not read file");
	if (!parse_file(file, &info))
		exit_error(&info, file, NULL);
	if (!extract_map_from_file(file, &info))
		exit_error(&info, file, "Extracting map failed");
	remove_newlines_from_map(info.map);
	if (!valid_map(info.map, &info))
		exit_error(&info, file, NULL);
	if (init_game(&game, &info) != 0)
		exit_error(&info, file, "Game initialization failed");
	game.map = info.map;
	set_player_start(&game);
	draw_scene(&game);
	mlx_resize_hook(game.mlx, window_resize, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	free_resources(&info);
	free_map(file);
	free_game(&game);
	return (0);
}
