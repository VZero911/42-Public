/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 01:40:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printf_char(t_struct *data)
{
	int     c;
	char    padding;
	int     padlen;

	c = data->var.c;
	padlen = data->width - 1;
	padding = padding_char(data);
	if (data->flags == FLAG_LEFT_ALIGN)
	{
		ft_putchar_fd(c ,1);
		apply_padding(padding, padlen);
	}
	else
	{
		apply_padding(padding, padlen);
		ft_putchar_fd(c ,1);
	}
	if (data->width > 1)
		ft_data_len(data, data->width);
	else
		ft_data_len(data, 1);
}

void	ft_printf_pointer(t_struct *data)
{
	void	*ptr;
	char	*print_str;
	int		strlen;
	int		padlen;
	char	padding;

	ptr = data->var.p;
	if (ptr == NULL)
		print_str = ft_strdup("(nil)");
	else
		print_str = ft_pointer_to_str((t_ull)ptr, HEXA);
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

void	ft_printf_percentage(t_struct *data)
{
	ft_putchar_fd('%', 1);
	ft_data_len(data, 1);
}
