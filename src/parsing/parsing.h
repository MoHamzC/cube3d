/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:26:06 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/29 01:17:39 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#include "libft/libft.h"
#include "getnextline/get_next_line.h"

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	hex;
	int	defined;
}	t_color;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_info
{
	t_texture	texture;	
	t_color		floor;		
	t_color		ceiling;	
	char		**map;		
	int			map_height;
	int			map_width;
	t_player	player;		
}	t_info;

void	remove_newlines_from_map(char **map);
int		exit_error(t_info *info, char **file, const char *msg);
int		count_map_lines(char **file_lines, int start);
int		is_invalid(char **map, int y, int x);
int		is_digit_str_trimmed(char *s);
int		extract_map_from_file(char **file_lines, t_info *info);
int		handle_line(char *line, t_info *info);
int		check_args(int ac, char *av[]);
int		is_empty_line_in_map(char **map);
int		is_txt(char *line);
char	*puttheline(int fd);
char	**get_file(int fd);
void	free_map(char **map);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_digit_str(char *s);
void	handle_memory_error(void);
int		is_line_empty(char *line);
int		is_color(char *line);
int		get_color(char *line, t_info *info);
int		get_txt(char *line, t_info *info);
int		goteverything(t_info *info);
void	free_resources(t_info *info);
int		parse_file(char **file, t_info *info);
char	*get_path(char *line);
int		is_map_closed(char **map);
int		is_there_a_player(char **map);
int		is_map_closed(char **map);
int		valid_char(char c);
int		valid_map(char **map, t_info *info);
int		is_valid_char(char **map, t_info *info);
int		rgb_to_hex(int r, int g, int b);
void	init_struct(t_info *info);
int		extract_map_from_file(char **file_lines, t_info *info);
void	free_split(char **split);
char	*trim_spaces(char *s);