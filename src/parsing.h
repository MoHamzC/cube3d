#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

# include "libft/libft.h"
# include "getnextline/get_next_line.h"

int valid_char(char c);
int valid_map(char *map); 
char *puttheline(int fd);
char *get_map(int fd);
int valid_chars(char *map);
void	handle_memory_error(void);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int is_map_closed(char **map);
void free_map(char **map);
int check_args(int ac, char *av[]);

