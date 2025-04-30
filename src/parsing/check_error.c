/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:11:15 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/29 01:20:57 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

int	is_map_closed(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '\n' && map[y][x] != '1' && map[y][x] != ' ')
			{
				if (is_invalid(map, y, x))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	is_there_a_player(char **map)
{
	int	x;
	int	y;
	int	nb_player;

	y = 0;
	nb_player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '\n')
			{
				if (map[y][x] == 'N' || map[y][x] == 'S' ||
					map[y][x] == 'E' || map[y][x] == 'W')
					nb_player++;
			}
			x++;
		}
		y++;
	}
	return (nb_player == 1);
}

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
