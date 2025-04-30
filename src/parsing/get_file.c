/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:23:46 by mtarento          #+#    #+#             */
/*   Updated: 2025/05/01 01:06:57 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**ft_realloc(char **old, int old_size, int new_size)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (new_size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new[i] = old[i];
		i++;
	}
	new[i] = NULL;
	free(old);
	return (new);
}

char	*puttheline(int fd)
{
	char	*line;
	char	*buffer;
	char	*temp;

	buffer = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(buffer, line);
		free(buffer);
		buffer = temp;
		free(line);
		if (!buffer)
			handle_memory_error();
		line = get_next_line(fd);
	}
	return (buffer);
}

char	**get_file(int fd)
{
	char	**map;
	char	*line;
	int		size;

	size = 0;
	map = malloc(sizeof(char *) * 1);
	if (!map)
		handle_memory_error();
	map[0] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		map = ft_realloc(map, size, size + 1);
		if (!map)
			handle_memory_error();
		map[size] = line;
		map[size + 1] = NULL;
		size++;
		line = get_next_line(fd);
	}
	return (map);
}

void	remove_newlines_from_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '\n')
				map[y][x] = '\0';
			x++;
		}
		y++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
