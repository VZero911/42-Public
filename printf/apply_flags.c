/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 04:29:53 by marvin           ###   ########.fr       */
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

char *handle_precision_and_strdup(char *str, t_struct *data)
{
	char	*print_str;
	int		strlen;
	
	strlen = ft_strlen(str);
	if (data->precision != -1 && data->precision < strlen)
		print_str = ft_substr(str, 0, data->precision);
	else
		print_str = ft_strdup(str);
	return (print_str);
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