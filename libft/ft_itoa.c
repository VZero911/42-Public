/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:26:41 by pthuilli          #+#    #+#             */
/*   Updated: 2024/10/25 01:32:57 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

char	*ft_itoa(int n)
{
	static char	*str;
	static int	i;
	long		nb;

	if (!str)
	{
		str = (char *)malloc(12);
		if (!str)
			return (NULL);
		ft_bzero(str, 12);
		i = 0;
		nb = n;
		if (nb < 0)
		{
			str[i++] = '-';
			nb = -nb;
		}
		else if (n == 0)
			str[i++] = '0';
	}
	nb = (n < 0) ? -(long)n : n;
	if (nb > 9)
		ft_itoa(nb / 10);
	str[i++] = (nb % 10) + '0';
	return (str);
}
