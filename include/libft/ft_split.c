/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:18:21 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:46:02 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strings(const char *s, char delimiter)
{
	size_t	strings;

	strings = 0;
	while (*s)
	{
		while (*s == delimiter && *s)
			++s;
		if (*s != delimiter && *s)
		{
			++strings;
			while (*s != delimiter && *s)
				++s;
		}
	}
	return (strings);
}

static int	safe_malloc(char **matrix, int position, size_t buffer)
{
	matrix[position] = malloc(buffer);
	if (NULL == matrix[position])
	{
		while (position >= 0)
			free(matrix[position--]);
		free(matrix);
		return (1);
	}
	return (0);
}

static int	fill_matrix(char **matrix, const char *s, char delimiter)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimiter)
			++s;
		while (*s != delimiter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (safe_malloc(matrix, i, len + 1))
				return (1);
			ft_strlcpy(matrix[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	strings;
	char	**matrix;

	if (s == NULL)
		return (NULL);
	strings = count_strings(s, c);
	matrix = malloc((strings + 1) * sizeof(char *));
	if (NULL == matrix)
		return (NULL);
	matrix[strings] = NULL;
	if (fill_matrix(matrix, s, c))
		return (NULL);
	return (matrix);
}

/* Test
int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("hello! world", ' ');
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}
*/
