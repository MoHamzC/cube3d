/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:42:47 by mtarento          #+#    #+#             */
/*   Updated: 2025/04/04 17:17:45 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (i == n)
        return (0);
    return (s1[i] - s2[i]);
}

int valid_char(char c)
{
    return(c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '\n' || c == ' ');
}

void	handle_memory_error(void)
{
	printf("Error: malloc problem !!!\n");
	exit(1);
}