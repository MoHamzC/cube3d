/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:02:10 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/30 22:49:33 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_path(char *line)
{
	char	*trimmed;
	char	*path;

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

int	set_texture(char **texture, char *path, char *msg)
{
	if (*texture)
		return (printf("%s", msg), 0);
	*texture = path;
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
