/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarento <mtarento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:35:56 by mtarento          #+#    #+#             */
/*   Updated: 2023/11/11 22:31:25 by mtarento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	u1;
	unsigned char	u2;

	i = 0;
	while (i < n)
	{
		u1 = (unsigned char)s1[i];
		u2 = (unsigned char)s2[i];
		if (u1 != u2 || u1 == '\0' || u2 == '\0')
		{
			return (u1 - u2);
		}
		i++;
	}
	return (0);
}
/* int main(void)
{
    const char s1[] = "Salut, comment tu vas ?";
    const char s2[] = "aALUT COMMENT CA VA ?";

    int result = ft_strncmp(s1, s2, 1);

    if (result == 0)
    {
        write(1, "deux chaînes identiques.\n", 33);
    }
    else if (result < 0)
    {
        write(1, "première chaîne inférieure\n", 33);
    }
    else
    {
        write(1, "première chaîne supérieure deuxième.\n", 48);
    }

    return (0);
} */
