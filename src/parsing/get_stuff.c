/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:02:10 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/09 05:29:23 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_path(char *line)
{
	while (*line && *line != ' ')
		line++;
	while (*line == ' ')
		line++;
	return (ft_strdup(line));
}

int	is_digit_str_trimmed(char *s)
{
	while (*s == ' ')
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	get_color(char *line, t_info *info)
{
	t_color	*color;
	char	**split;

	if (line[0] == 'F')
		color = &info->floor;
	else if (line[0] == 'C')
		color = &info->ceiling;
	else
		return (0);
	line += 2;
	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (free_split(split), printf("Error: invalid RGB format\n"), 0);
	if (!is_digit_str_trimmed(split[0]) || !is_digit_str_trimmed(split[1]) || !is_digit_str_trimmed(split[2]))
		return (free_split(split), printf("Error: invalid RGB number\n"), 0);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	if (color->r < 0 || color->r > 255 ||
		color->g < 0 || color->g > 255 ||
		color->b < 0 || color->b > 255)
		return (free_split(split), printf("Error: color value must be between 0 and 255\n"), 0);

	color->defined = 1;
	return (free_split(split), 1);
}

int get_txt(char *line, t_info *info)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (info->texture.north != NULL)
			return (printf("Error: repeat texture for NO\n"), 0);
		info->texture.north = get_path(line);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (info->texture.south != NULL)
			return (printf("Error: repeat texture for SO\n"), 0);
		info->texture.south = get_path(line);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (info->texture.west != NULL)
			return (printf("Error: repeat texture for WE\n"), 0);
		info->texture.west = get_path(line);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (info->texture.east != NULL)
			return (printf("Error: repeat texture for EA\n"), 0);
		info->texture.east = get_path(line);
	}
	return (1);
}