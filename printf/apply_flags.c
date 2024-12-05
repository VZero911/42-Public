/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/05 15:28:38 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_and_pad(char *print_str, int padlen, char padding, t_struct *data)
{
	int	strlen;

	strlen = ft_strlen(print_str);
	if (data->flags & FLAG_LEFT_ALIGN)
	{
		write(1, print_str, strlen);
		apply_padding(padding, padlen);
	}
	else
	{
		apply_padding(padding, padlen);
		write(1, print_str, strlen);
	}
}

char	padding_char(t_struct *data)
{
	char	padding_char;

	if (data->flags == FLAG_ZERO_PADDING)
		padding_char = '0';
	else
		padding_char = ' ';
	return (padding_char);
}

void	apply_padding(char pad_char, int len)
{
	while (len > 0)
	{
		write(1, &pad_char, 1);
		len--;
	}
}

void	ft_data_len(t_struct *data, int len)
{
	data->len += len;
}

char	*apply_int_precision(char *nb_str, t_struct *data)
{
	int		precision_len;
	int		nb_len;
	char	*precision_str;

	if (data->precision == -1)
		return (nb_str);
	nb_len = ft_strlen(nb_str);
	precision_len = data->precision - nb_len;
	if (precision_len <= 0)
		return (nb_str);
	precision_str = ft_calloc(data->precision + 1, sizeof(char));
	if (!precision_str)
	{
		free(nb_str);
		return (NULL);
	}
	ft_memset(precision_str, '0', precision_len);
	ft_memcpy(precision_str + precision_len, nb_str, nb_len);
	free(nb_str);
	return (precision_str);
}
