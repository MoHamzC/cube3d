/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:13:20 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/30 23:09:35 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**parse_color_line(char *line)
{
	char	*clean;
	char	**split;

	clean = ft_strtrim(line, " \n\t\r\v\f");
	if (!clean)
		return (NULL);
	split = ft_split(clean, ',');
	free(clean);
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		free_split(split);
		printf("Error: invalid RGB format\n");
		return (NULL);
	}
	if (!is_digit_str_trimmed(split[0])
		|| !is_digit_str_trimmed(split[1]) || !is_digit_str_trimmed(split[2]))
	{
		free_split(split);
		printf("Error: invalid RGB number\n");
		return (NULL);
	}
	return (split);
}

int	fill_color(t_color *color, char **split)
{
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		printf("Error: color value must be between 0 and 255\n");
		return (0);
	}
	color->defined = 1; 
	color->hex = rgb_to_hex(color->r, color->g, color->b);
	return (1);
}

int	get_color(char *line, t_info *info)
{
	t_color	*color;
	char	**split;

	if (line[0] == 'F')
		color = &info->floor;
	else
		color = &info->ceiling;
	line += 2;
	while (*line == ' ')
		line++;
	split = parse_color_line(line);
	if (!split)
		return (0);
	if (!fill_color(color, split))
		return (free_split(split), 0);
	free_split(split);
	return (1);
}
