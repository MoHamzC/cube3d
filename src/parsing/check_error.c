
#include "parsing.h"

int check_args(int ac, char *av[])
{
    int len; 

    len = 0; 
    if(ac != 2)
    {
        printf("not good amout of args\n");
        return(1);
    }
    len = ft_strlen(av[1]); 
    if (len < 4 || ft_strncmp(&av[1][len - 4], ".cub", 4) != 0)
	{
		printf("error\n not a .cub\n");
		return (1);
	}
    return(0); 
}

int valid_chars(char *map)
{
    int i; 
    int nbchar;
    
    nbchar = 0;
    i = 0; 
    while(map[i])
    {
        if (!valid_char(map[i]))
        {
            printf("error: Invalid char\n");
            return (0);
        }

        if(map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] == 'W')
            nbchar++; 
        i++; 
    }
    if(nbchar != 1)
    {
        printf("error: empty map\n");
        return(0); 
    }
    return (1);
}

int is_map_closed(char **map)
{
    int x, y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            char c = map[y][x];
            if (c != '1' && c != ' ')
            {
                if (!map[y + 1] || y == 0 || !map[y][x + 1] || x == 0)
                    return (0);
                if (!map[y - 1][x] || map[y - 1][x] == ' ' ||
                    !map[y + 1][x] || map[y + 1][x] == ' ' ||
                    !map[y][x - 1] || map[y][x - 1] == ' ' ||
                    !map[y][x + 1] || map[y][x + 1] == ' ')
                    return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}

int valid_map(char *map)
{
    char **map2;
    if (!valid_chars(map))
    {
        free(map);
        return(0); 
    }
    map2 = ft_split(map, '\n');
    free(map); 
    if(!is_map_closed(map2))
    {
        printf("error: map not closed\n");
        free_map(map2);
        return(0); 
    }
	printf("map is valid\n");
	//putmapinsidestructurehere
    return (1);
}