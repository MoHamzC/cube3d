/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:45:56 by mtarento          #+#    #+#             */
/*   Updated: 2025/05/01 00:26:24 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == '\n'
		|| (c >= 9 && c <= 13) || c == ' ');
}

int	is_empty_line_in_map(char **map)
{
	int	i;
	int	started;

	i = 0;
	started = 0;
	while (map[i])
	{
		if (is_line_empty(map[i]))
		{
			if (started)
				return (1);
		}
		else
			started = 1;
		i++;
	}
	return (0);
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
				return (0);
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
	if (!map[y] || (int)ft_strlen(map[y]) <= x)
		return (1);
	if (!map[y + 1] || (int)ft_strlen(map[y + 1]) <= x
		|| map[y + 1][x] == ' ' || map[y + 1][x] == '\n')
		return (1);
	if (y == 0 || !map[y - 1] || (int)ft_strlen(map[y - 1]) <= x
		|| map[y - 1][x] == ' ' || map[y - 1][x] == '\n')
		return (1);
	if (x == 0 || !map[y][x - 1] || map[y][x - 1] == ' '
		|| map[y][x - 1] == '\n')
		return (1);
	if (!map[y][x + 1] || map[y][x + 1] == ' '
		|| map[y][x + 1] == '\n')
		return (1);
	return (0);
}

int	valid_map(char **map, t_info *info)
{
	if (!map || !map[0])
		return (fprintf(stderr, "Error\n map is NULL\n"), 0);
	if (!is_valid_char(map, info))
	{
		fprintf(stderr, "Error\n invalid character in map\n");
		return (0);
	}
	if (!is_map_closed(map))
	{
		fprintf(stderr, "Error\n map is not closed\n");
		return (0);
	}
	if (!is_there_a_player(map))
	{
		fprintf(stderr, "Error\n must be 1 player in map\n");
		return (0);
	}
	if (is_empty_line_in_map(map))
	{
		fprintf(stderr, "Error\n empty line in map\n");
		return (0);
	}
	return (1);
}
