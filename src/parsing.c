/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:14:15 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/04 17:42:42 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"

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

char	*get_map(int fd)
{
	char	*buffer;

	buffer = puttheline(fd);
	return (buffer);
}

void free_map(char **map)
{
    int i; 

    i = 0; 
    while(map[i])
    {
        free(map[i]);
        i++; 
    }
    free(map); 
}
