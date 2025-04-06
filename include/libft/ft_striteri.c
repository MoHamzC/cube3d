/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:51:57 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 21:30:01 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))

{
	int	y;
	int	i;

	y = 0;
	i = 0;
	if (s != NULL && f != NULL)
	{
		y = ft_strlen(s);
		while (i < y)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
