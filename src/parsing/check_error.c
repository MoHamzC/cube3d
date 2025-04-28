/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:11:15 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/28 23:50:49 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
