/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:26:52 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 18:33:10 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *chat, const char *chaton, size_t len)

{
	size_t	chaton_len;

	chaton_len = ft_strlen(chaton);
	if (*chaton == '\0')
		return ((char *)chat);
	while (*chat && len >= chaton_len)
	{
		if (ft_strncmp(chat, chaton, chaton_len) == 0)
			return ((char *)chat);
		chat++;
		len--;
	}
	return (NULL);
}

/*
char	*ft_strnstr(const char *chat, const char *chaton, size_t len)
{
	size_t	chaton_len;

    if (*chaton == '\0')
        return ((char *)chat);
    chaton_len = strlen(chaton);
    while (*chat && len >= chaton_len)
    {
        if (strncmp(chat, chaton, chaton_len) == 0)
            return ((char *)chat);
        chat++;
        len--;
    }
    return (NULL);
}
*/
