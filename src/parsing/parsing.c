#include "parsing.h"

void init_struct(t_info *info)
{
	info->texture.north = NULL;
	info->texture.south = NULL;
	info->texture.east = NULL;
	info->texture.west = NULL;
	info->floor.r = -1; 
	info->floor.g = - 1; 
	info->floor.b = -1;
	info->floor.defined = 0;
	info->ceiling.r = -1; 
	info->ceiling.g = info->ceiling.b = -1;
	info->ceiling.defined = 0;
	info->map_height = 0;
	info->map_width = 0;
}

int goteverything(t_info *info)
{
    if (info->texture.north && info->texture.south && info->texture.west && info->texture.east
	    && info->floor.defined && info->ceiling.defined)
		{
			return(1); 
		}
	return (0);
}

void free_resources(t_info *info)
{
	if(info->texture.north)
		free(info->texture.north);
	if(info->texture.south)
		free(info->texture.south);
	if(info->texture.west)
		free(info->texture.west);
	if(info->texture.east)
		free(info->texture.east);
}

int parse_file(char **file, t_info *info)
{
	int y;
	
	y = 0;
	init_struct(info);
    while (file[y] && !goteverything(info))
{
	if (is_line_empty(file[y]))
		y++;
	else if (is_color(file[y]))
	{
		if (!get_color(file[y], info))
			return (fprintf(stderr, "error: invalid color line\n"), 0);
		y++; 
	}
	else if (is_txt(file[y]))
	{
		get_txt(file[y], info);
		y++; 
	}
	else
		return (fprintf(stderr, "error: invalid line\n"), 0);
}
	if (!goteverything(info))
	{
		fprintf(stderr, "error: missing textures or colors\n");
		free_resources(info);
		return (0);
	}
	return (1);
}
