/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:07:43 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:45:28 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	chat[];
	char	chat2[];

    chat[] = "chacha";
    ft_bzero(chat, 3); 
    printf("ft_bzero: %s\n", chat);
    chat2[] = "chacha";
    bzero(chat2, 3); 
    printf("bzero: %s\n", chat2);
    return (0);
}

*/
