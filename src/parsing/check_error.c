#include "parsing.h"


int valid_char(char c)
{
    return(c == '0' || c == '1' || c == 'N' || c == 'S'
        || c == 'E' || c == 'W' || c == '\n' || (c >= 9 && c <= 13) || c == ' ');
}

int is_valid_char(char **map, t_info *info)
{
    int x; 
    int y; 

    x = 0; 
    y = 0; 
    while(map[y])
    {
        x = 0; 
        while(map[y][x])
        {
            if(!valid_char(map[y][x]))
            {
                printf("invalid character in map\n");
                return(0); 
            }
            x++; 
        }
        y++;
    }
    info->map_height = y;
    info->map_width = x;
    return(1);
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

int is_there_a_player(char **map)
{
    int x; 
    int y;
    int nb_player;

    y = 0;
    x = 0; 
    nb_player = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'N' || map[y][x] == 'S' ||
                map[y][x] == 'E' || map[y][x] == 'W')
                nb_player++;
            x++;
        }
        y++;
    }
    return(nb_player == 1); 
}


int valid_map(char **map, t_info *info)
{
	if (!map || !map[0])
	{
		fprintf(stderr, "Error\n map is NULL\n");
		return (0);
	}
	if (!is_valid_char(map, info))
	{
		fprintf(stderr, "Error\n invalid character in map\n");
		return (0);
	}

	if (!is_map_closed(map))
	{
		fprintf(stderr, "Error\n map is not closed\n");
		return (0);
	}
	if (!is_there_a_player(map))
	{
		fprintf(stderr, "Error\n must be 1 player in map\n");
		return (0);
	}
	return (1);
}

