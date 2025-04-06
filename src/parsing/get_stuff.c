#include "parsing.h"

char *get_path(char *line)
{
	while (*line && *line != ' ')
		line++;
	while (*line == ' ')
		line++;
	return (ft_strdup(line));
}

int get_color(char *line, t_info *info)
{
	t_color *color;
	char **split;

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
	if (!split || !split[0] || !split[1] || !split[2])
		return (free_split(split), 0);
	if (!is_digit_str(split[0]) || !is_digit_str(split[1]) || !is_digit_str(split[2]))
		return (free_split(split), 0);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255 || color->b < 0 || color->b > 255)
		return (free_split(split), printf("Error\n color value not be between 0 and 255\n"), 0);
	color->defined = 1;
	color->hex = rgb_to_hex(color->r, color->g, color->b);
	printf("hex=0x%06x\n", color->hex);
	return (free_split(split), 1);
}

void get_txt(char *line, t_info *info)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
	    info->texture.north = get_path(line);
    else if (ft_strncmp(line, "SO ", 3) == 0)
	    info->texture.south = get_path(line);
    else if (ft_strncmp(line, "WE ", 3) == 0)
	    info->texture.west = get_path(line);
    else if (ft_strncmp(line, "EA ", 3) == 0)
	    info->texture.east = get_path(line);
}