/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:16:02 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 21:55:25 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;
	char		searched;

	last = NULL;
	searched = (char)c;
	while (*str)
	{
		if (*str == searched)
			last = str;
		str++;
	}
	if (searched == '\0')
	{
		return ((char *)(str));
	}
	if (last != NULL)
		return ((char *)last);
	return (NULL);
}
/*
int	main(void) 
{
	printf("%s\n", ft_strrchr("ch", "chat"));
	return(0);
}
*/
