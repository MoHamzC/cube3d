/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:48:46 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:46:07 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		src_len;
	char		*d;
	const char	*s;
	size_t		space_left;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	d = dst + dst_len;
	s = src;
	space_left = size - dst_len - 1;
	while (*s && space_left > 0)
	{
		*d++ = *s++;
		space_left--;
	}
	*d = '\0';
	return (dst_len + src_len);
}

/*
int	main(void)
{
	char	dest[] = "mmm me mmmm mmm!";
	char	src[] = "mmm a mmm, mmm mmmm mmmm o mmmm mmmmmmm!";
	printf("%d",ft_strlcat(dest, src, 5));
}*/