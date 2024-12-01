/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/01 22:22:16 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_digits(unsigned long long n, int base_len)
{
	size_t	count;

	count = 1;
	while (n >= (unsigned long long)base_len)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

char	*ft_ulltoa_base(unsigned long long n, const char *base)
{
	char	*result;
	size_t	base_len;
	size_t	num_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (NULL);
	num_len = ft_count_digits(n, base_len);
	result = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	while (num_len > 0)
	{
		result[--num_len] = base[n % base_len];
		n /= base_len;
	}
	return (result);
}

char	*ft_pointer_to_str(unsigned long long ptr, const char *base)
{
	char	*str;
	char	*prefix;
	char	*hex;

	prefix = ft_strdup("0x");
	hex = ft_ulltoa_base(ptr, base);
	str = ft_strjoin(prefix, hex);
	free(prefix);
	free(hex);
	return (str);
}
