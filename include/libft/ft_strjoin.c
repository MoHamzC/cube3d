/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:15:05 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:46:06 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	ch1;
	size_t	ch2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	ch1 = ft_strlen(s1);
	ch2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (ch1 + ch2 + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, ch1 + 1);
	ft_strlcat(dest, s2, ch1 + ch2 + 1);
	return (dest);
}
/*int	main(void)
{
	char	str[] = "Chachacha";
	char	str1[] = "Chachacha!";
	printf("%d", str, str1);
	return(0);
}*/
