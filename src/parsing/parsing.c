/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:17:35 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/09 05:31:08 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_map(char **map, t_info *info)
{
	if (!map || !map[0])
	{
		fprintf(stderr, "Error\n map is NULL\n");
		return (0);
	}
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
	// if(is_empty_line_in_map(map))
	// {
	// 	fprintf(stderr, "Error\n empty line in map\n");
	// 	return (0);
	// }
	return (1);
}

void	init_struct(t_info *info)
{
	info->texture.north = NULL;
	info->texture.south = NULL;
	info->texture.east = NULL;
	info->texture.west = NULL;
	info->floor.r = -1;
	info->floor.g = -1;
	info->floor.b = -1;
	info->floor.defined = 0;
	info->ceiling.r = -1;
	info->ceiling.g = -1;
	info->ceiling.b = -1;
	info->ceiling.defined = 0;
	info->map_height = 0;
	info->map_width = 0;
}

int	goteverything(t_info *info)
{
	if (info->texture.north && info->texture.south
		&& info->texture.west && info->texture.east
		&& info->floor.defined && info->ceiling.defined)
	{
		return (1);
	}
	return (0);
}

void	free_resources(t_info *info)
{
	if (info->texture.north)
		free(info->texture.north);
	if (info->texture.south)
		free(info->texture.south);
	if (info->texture.west)
		free(info->texture.west);
	if (info->texture.east)
		free(info->texture.east);
}

int parse_file(char **file, t_info *info)
{
	int y = 0;

	init_struct(info);
	while (file[y] && !goteverything(info))
	{
		if (is_line_empty(file[y]))
			y++;
		else if (is_color(file[y]))
		{
			if (!get_color(file[y], info))
				return (printf("error: invalid color line\n"), 0);
			y++;
		}
		else if (is_txt(file[y]))
		{
			if (!get_txt(file[y], info))
				return (0);
			y++;
		}
		else
			return (printf("error: invalid line\n"), 0);
	}
	if (!goteverything(info))
	{
		printf("error: missing textures or colors\n");
		free_resources(info);
		return (0);
	}
	return (1);
}