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

static char	*handle_zero_case_and_padding(char *nb_str, int nb, t_struct *data)
{
	if (nb == 0 && data->precision == 0)
	{
		free(nb_str);
		nb_str = ft_strdup("");
		if (!nb_str)
			return (NULL);
	}
	if ((data->flags & FLAG_ZERO_PADDING)
		&& !(data->flags & FLAG_LEFT_ALIGN) && data->precision == -1)
	{
		if (nb < 0)
			data->precision = data->width - 1;
		else
			data->precision = data->width;
		data->width = 0;
	}
	return (nb_str);
}

static char	*prepare_int_str(int nb)
{
	char	*nb_str;

	if (nb == INT_MIN)
	{
		nb_str = ft_strdup("2147483648");
		if (!nb_str)
			return (NULL);
		return (nb_str);
	}
	if (nb < 0)
		nb_str = ft_itoa(-nb);
	else
		nb_str = ft_itoa(nb);
	if (!nb_str)
		return (NULL);
	return (nb_str);
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

static char	*prepare_number(int nb, t_struct *data)
{
	char	*nb_str;

	nb_str = prepare_int_str(nb);
	if (!nb_str)
		return (NULL);
	nb_str = handle_zero_case_and_padding(nb_str, nb, data);
	if (!nb_str)
		return (NULL);
	nb_str = apply_int_precision(nb_str, data);
	if (!nb_str)
		return (NULL);
	nb_str = add_int_sign(nb_str, nb, data);
	return (nb_str);
}

void	ft_printf_int(t_struct *data)
{
	int		nb;
	char	*nb_str;
	int		padlen;
	int		strlen;
	char	padding;

	nb = data->var.i;
	nb_str = prepare_number(nb, data);
	if (!nb_str)
	{
		return ;
	}
	strlen = ft_strlen(nb_str);
	if (data->width > strlen)
		padlen = data->width - strlen;
	else
		padlen = 0;
	padding = padding_char(data);
	print_and_pad(nb_str, padlen, padding, data);
	if (!(data->width > strlen))
		data->width = strlen;
	ft_data_len(data, data->width);
	free(nb_str);
}
