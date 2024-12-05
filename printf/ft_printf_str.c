/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/05 15:26:29 by jdumay           ###   ########.fr       */
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

char	*ft_ulltoa_base(t_ull n, const char *base)
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

static char	*prepare_string(t_struct *data)
{
	char	*str;
	char	*print_str;

	str = data->var.s;
	if (!str)
	{
		if (data->precision == -1 || data->precision >= 6)
			str = "(null)";
		else
			str = "";
	}
	if (data->precision != -1 && data->precision < (int)ft_strlen(str))
		print_str = ft_substr(str, 0, data->precision);
	else
		print_str = ft_strdup(str);
	return (print_str);
}

void	ft_printf_string(t_struct *data)
{
	char	*print_str;
	int		strlen;
	int		padlen;
	char	padding;

	print_str = prepare_string(data);
	if (!print_str)
		return ;
	strlen = ft_strlen(print_str);
	if (data->width > strlen)
		padlen = data->width - strlen;
	else
		padlen = 0;
	padding = padding_char(data);
	print_and_pad(print_str, padlen, padding, data);
	if (!(data->width > strlen))
		data->width = strlen;
	ft_data_len(data, data->width);
	free(print_str);
}
