/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:39:55 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:46:04 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)

{
	char	*dest;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen(src);
	dest = (char *)malloc(l + 1);
	if (dest == NULL)
		return (NULL);
	while (i < l)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* int	main(void)
{
	char	source[];
	char	*dest;

	source[] = "adorable chat!";
	dest = ft_strdup(source);
	if (dest != NULL)
	{
		printf("Source: %s\n", source);
		printf("Dest: %s\n", dest);
		free(dest);
	}
 	else
	{
		printf("erreur\n");
	}
	return (0);
} 
*/
