/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 01:45:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prepare_int_str(int nb)
{
	char	*nb_str;
	int		is_negative;

	is_negative = (nb < 0);
	if (is_negative)
		nb_str = ft_itoa(-nb);
	else
		nb_str = ft_itoa(nb);
	if (!nb_str)
		return (NULL);
	return (nb_str);
}

static char	*apply_int_precision(char *nb_str, t_struct *data)
{
	char	*precision_str;
	int		precision_len;
	int		nb_len;

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

static char	*add_int_sign(char *nb_str, int nb, t_struct *data)
{
	char	sign_char;
	char	*signed_str;


	sign_char = 0;
	if (nb < 0)
		sign_char = '-';
	else if ((data->flags & FLAG_PLUS))
		sign_char = '+';
	else if (data->flags & FLAG_SPACE)
		sign_char = ' ';
	if (!sign_char)
		return (nb_str);
	signed_str = ft_calloc(ft_strlen(nb_str) + 2, sizeof(char));
	if (!signed_str)
	{
		free(nb_str);
		return (NULL);
	}
	signed_str[0] = sign_char;
	ft_memcpy(signed_str + 1, nb_str, ft_strlen(nb_str));
	free(nb_str);
	return (signed_str);
}

void	ft_printf_int(t_struct *data)
{
	int		nb;
	char	*nb_str;
	int		strlen;
	int		padlen;
	char	padding;

	nb = data->var.i;
	nb_str = prepare_int_str(nb);
	if (!nb_str)
		return ;
	if ((data->flags & FLAG_ZERO_PADDING) &&
		!(data->flags & FLAG_LEFT_ALIGN) &&
		data->precision == -1)
	{
		data->precision = data->width;
		data->width = 0;
	}
	nb_str = apply_int_precision(nb_str, data);
	if (!nb_str)
		return ;
   	nb_str = add_int_sign(nb_str, nb, data);
	if (!nb_str)
		return ;
	strlen = ft_strlen(nb_str);
	if (data->width > strlen)
		padlen = data->width - strlen;
	else
		padlen = 0;
	padding = padding_char(data);
	print_and_pad(nb_str, padlen, padding, data);
	ft_data_len(data, (data->width > strlen) ? data->width : strlen);
	free(nb_str);
}
