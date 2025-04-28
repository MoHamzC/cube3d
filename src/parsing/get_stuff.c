/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:02:10 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/28 23:37:10 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char *get_path(char *line)
{
    char *trimmed;
    char *path;

    while (*line == ' ')
        line++;
    trimmed = ft_strtrim(line, " \n\t\r\v\f");
    if (!trimmed)
        return (NULL);
    if (trimmed[0] == '\0') 
    {
		printf("Error:\n empty path\n");
        free(trimmed);
        return (NULL);
    }
    path = ft_strdup(trimmed);
    free(trimmed);
    return (path);
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

int get_color(char *line, t_info *info)
{
	t_color	*color;
	char	**split;
	char	*clean;

	if (line[0] == 'F')
		color = &info->floor;
	else if (line[0] == 'C')
		color = &info->ceiling;
	line += 2;
	while (*line == ' ')
		line++;
	clean = ft_strtrim(line, " \n\t\r\v\f"); 
	split = ft_split(clean, ',');
	free(clean);
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (free_split(split), printf("Error: invalid RGB format\n"), 0);
	if (!is_digit_str_trimmed(split[0]) || !is_digit_str_trimmed(split[1]) || !is_digit_str_trimmed(split[2]))
		return (free_split(split), printf("Error: invalid RGB number\n"), 0);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255 || color->b < 0 || color->b > 255)
		return (free_split(split), printf("Error: color value must be between 0 and 255\n"), 0);
	color->defined = 1;
	return (free_split(split), 1);
}

int	set_texture(char **texture_field, char *path, char *error_msg)
{
	if (*texture_field)
		return (printf("%s", error_msg), 0);
	*texture_field = path;
	return (1);
}

int	get_txt(char *line, t_info *info)
{
	if (!line)
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (set_texture(&info->texture.north, get_path(line + 2),
				"Error: repeat texture for NO\n"));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (set_texture(&info->texture.south, get_path(line + 2),
				"Error: repeat texture for SO\n"));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (set_texture(&info->texture.west, get_path(line + 2),
				"Error: repeat texture for WE\n"));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (set_texture(&info->texture.east, get_path(line + 2),
				"Error: repeat texture for EA\n"));
	return (printf("Error: invalid texture line\n"), 0);
}

// int get_txt(char *line, t_info *info)
// {
//     char *path;

//     if (ft_strncmp(line, "NO ", 3) == 0)
//     {
//         if (info->texture.north != NULL)
//             return (printf("Error: repeat texture for NO\n"), 0);
//         path = get_path(line + 2);
//         if (!path)
//             return (0);
//         info->texture.north = path;
//     }
//     else if (ft_strncmp(line, "SO ", 3) == 0)
//     {
//         if (info->texture.south != NULL)
//             return (printf("Error: repeat texture for SO\n"), 0);
//         path = get_path(line + 2);
//         if (!path)
//             return (0);
//         info->texture.south = path;
//     }
//     else if (ft_strncmp(line, "WE ", 3) == 0)
//     {
//         if (info->texture.west != NULL)
//             return (printf("Error: repeat texture for WE\n"), 0);
//         path = get_path(line + 2);
//         if (!path)
//             return (0);
//         info->texture.west = path;
//     }
//     else if (ft_strncmp(line, "EA ", 3) == 0)
//     {
//         if (info->texture.east != NULL)
//             return (printf("Error: repeat texture for EA\n"), 0);
//         path = get_path(line + 2);
//         if (!path)
//             return (0);
//         info->texture.east = path;
//     }
//     else
//         return (printf("Error: invalid texture line\n"), 0);
//     return (1);
// }
