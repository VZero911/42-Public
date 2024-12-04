/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 05:58:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_digits(t_ull n, int base_len)
{
	size_t	count;

	count = 1;
	while (n >= (t_ull)base_len)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

static char	*ft_ulltoa_base(t_ull n, const char *base)
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

char	*ft_pointer_to_str(t_ull ptr, const char *base)
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


void ft_printf_string(t_struct *data)
{
	char *str;
	char *print_str;
	int strlen;
	int padlen;
	char padding;

	str = data->var.s;
	if (!str)
	{
			str = "(null)";
	}
	print_str = handle_precision_and_strdup(str, data);
	strlen = ft_strlen(print_str);
	if (data->width > strlen)
		padlen = data->width - strlen;
	else
		padlen = 0;
	padding = padding_char(data);
	print_and_pad(print_str, padlen, padding, data);
	if (data->width > strlen)
		ft_data_len(data, data->width);
	else
		ft_data_len(data, strlen);
	free(print_str);
}
