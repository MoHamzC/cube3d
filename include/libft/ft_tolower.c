/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:09:28 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:46:18 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <unistd.h> */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/* int	main(void)
{
	char str[] = "ADORABLE";
	ft_tolower(str);
	write(1, str, 8);
	return (0);
} */
