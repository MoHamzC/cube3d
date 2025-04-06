/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:16:19 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 17:45:35 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
int	main(void) {
    char str[] = "He/llo";

    if (ft_isalpha(str) == 0)
    {
        write(1, "0", 1);
    } 
    else 
    {
        write(1, "1", 1);
    }
    return (0);
}
*/
