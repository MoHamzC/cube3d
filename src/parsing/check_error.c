/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:11:15 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/08 21:12:41 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == '\n'
		|| (c >= 9 && c <= 13) || c == ' ');
}

int	is_valid_char(char **map, t_info *info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!valid_char(map[y][x]))
			{
				printf("invalid character in map\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	info->map_height = y;
	info->map_width = x;
	return (1);
}

int	is_invalid(char **map, int y, int x)
{
	return (!map[y + 1] || y == 0 || !map[y][x + 1] || x == 0 ||
		!map[y - 1][x] || map[y - 1][x] == ' ' ||
		!map[y + 1][x] || map[y + 1][x] == ' ' ||
		!map[y][x - 1] || map[y][x - 1] == ' ' ||
		!map[y][x + 1] || map[y][x + 1] == ' ');
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
			if (map[y][x] != '1' && map[y][x] != ' ')
				if (is_invalid(map, y, x))
					return (0);
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
	x = 0;
	nb_player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' ||
				map[y][x] == 'E' || map[y][x] == 'W')
				nb_player++;
			x++;
		}
		y++;
	}
	return (nb_player == 1);
}
