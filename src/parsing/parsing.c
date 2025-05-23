/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:17:35 by mtarento          #+#    #+#             */
/*   Updated: 2025/05/01 02:41:00 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	info->map = NULL;
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

int	handle_line(char *line, t_info *info)
{
	if (is_line_empty(line))
		return (1);
	if (is_color(line))
		return (get_color(line, info));
	if (is_txt(line))
		return (get_txt(line, info));
	printf("Error: invalid line: %s\n", line);
	return (0);
}

int	parse_file(char **file, t_info *info)
{
	int	y;

	y = 0;
	init_struct(info);
	while (file[y] && !goteverything(info))
	{
		if (!handle_line(file[y], info))
			return (0);
		y++;
	}
	if (!goteverything(info))
		return (printf("error: missing textures or colors\n"), 0);
	return (1);
}
