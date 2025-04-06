/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:10:11 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:45:30 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}

/*
int	main(void)
{
	char	chat[];
	char	chat2[];

	chat[] = "chacha";
	ft_calloc(chat, 3);
	printf("ft_calloc: %s\n", chat);
	chat2[] = "chacha";
	calloc(chat2, 3);
	printf("calloc: %s\n", chat2);
	return (0);
}

*/
