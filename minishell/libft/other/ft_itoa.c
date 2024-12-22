/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 23:57:51 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_count(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	size = ft_count(n);
	result = ft_calloc(size + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	result[size] = 0;
	while (n > 0)
	{
		result[--size] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
