/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:36:35 by mtarento          #+#    #+#             */
/*   Updated: 2024/04/23 18:47:50 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_fd(int fd, char *str)
{
	char	*buffer;
	ssize_t	nb_read;
	char	*temp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb_read = read(fd, buffer, BUFFER_SIZE);
	while (nb_read > 0)
	{
		buffer[nb_read] = '\0';
		temp = str;
		str = ft_strjoin (temp, buffer);
		free(temp);
		if (ft_strchr(str, '\n'))
			break ;
		nb_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if ((nb_read < 0) || (nb_read == 0 && (!str || *str == '\0')))
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*create_line(char *str, size_t i)
{
	char	*line;
	size_t	j;

	j = 0;
	if (!str)
		return (NULL);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*trim_str(char *str, size_t i)
{
	char	*new_str;

	new_str = ft_strdup(str + i);
	if (!(new_str))
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (new_str);
}

char	*extract_line(char *str, char **trimmed_str)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = create_line(str, i);
	if (!line)
		return (NULL);
	*trimmed_str = trim_str(str, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_from_fd(fd, str);
	if (!str)
		return (NULL);
	line = extract_line(str, &str);
	return (line);
}

/*int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		write(1, "erreur", 6);
		return (1);
	}
	while((line = get_next_line(fd)))
	{
		printf("%s", line); 
		free(line); 
	}
	if (line)
		free(line);
	close(fd);

	return 0;
}*/
