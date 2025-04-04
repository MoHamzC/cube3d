/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:16:05 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:46:11 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = -1;
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[++i])
	{
		dest[i] = (*f)(i, s[i]);
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	const char	dest[] = "mmm me mmmm mmm!";
	const char	src[] = "mmm a mmm, mmm mmmm mmmm o mmmm mmmmmmm!";
	printf("%d",ft_strlcpy(dest, src, 10));
}*/