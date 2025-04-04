/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:15:18 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 21:46:35 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	main(void)
{
	char str[] = "1";

	if (ft_isprint(str) == 1)
	{
		write(1, "1", 1);
	}
	else
	{
		write(1, "0", 1);
	}

	return (0);
} */
