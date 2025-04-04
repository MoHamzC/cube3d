/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:12:29 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:52:27 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void) {
    char str[] = "chat";

    if (ft_isascii(str) == 0)
        write(1, "0", 1);
    else
        write(1, "1", 1);

    return (0);
}
*/
