/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:10:31 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 18:12:27 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (dest);
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char str[] = "chat";
	char dest[5];
	ft_memcpy(dest, str, 5);
	dest[4] = '\0'; 
	ft_putstr_fd(dest, 1);
	ft_putchar_fd('\n', 1);
} */
