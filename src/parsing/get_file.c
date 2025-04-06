
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

char	**get_file(int fd)
{
	char	*buffer;
    char    **map; 
	buffer = puttheline(fd);
	map = ft_split(buffer, '\n');
    free(buffer);
    return(map); 
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