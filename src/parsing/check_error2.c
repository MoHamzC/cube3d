/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:45:56 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/28 23:51:32 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"

int	valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == '\n'
		|| (c >= 9 && c <= 13) || c == ' ');
}

int is_empty_line_in_map(char **map)
{
	int i;
	int found_non_empty;

	i = 0;
	found_non_empty = 0;
	while (map[i])
	{
		if (is_line_empty(map[i]))
		{
			if (found_non_empty)
				return (1); 
		}
		else
			found_non_empty = 1;
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
	if (!map[y] || (int)ft_strlen(map[y]) <= x)
		return (1);
	if (!map[y + 1] || (int)ft_strlen(map[y + 1]) <= x ||
		map[y + 1][x] == ' ' || map[y + 1][x] == '\n')
		return (1);
	if (y == 0 || !map[y - 1] || (int)ft_strlen(map[y - 1]) <= x ||
		map[y - 1][x] == ' ' || map[y - 1][x] == '\n')
		return (1);
	if (x == 0 || !map[y][x - 1] || map[y][x - 1] == ' ' ||
		map[y][x - 1] == '\n')
		return (1);
	if (!map[y][x + 1] || map[y][x + 1] == ' ' ||
		map[y][x + 1] == '\n')
		return (1);
	return (0);
}
