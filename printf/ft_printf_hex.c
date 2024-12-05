/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/05 15:32:08 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_with_prefix(const char *prefix, const char *str)
{
	if (*prefix)
		write(1, prefix, ft_strlen(prefix));
	write(1, str, ft_strlen(str));
}

static void	print_and_pad_with_prefix(const char *prefix,
			const char *str, int padlen, t_struct *data)
{
	char	padding;

	padding = padding_char(data);
	if (!(data->flags & FLAG_LEFT_ALIGN))
		while (padlen-- > 0)
			write(1, &padding, 1);
	if (*prefix)
		write(1, prefix, ft_strlen(prefix));
	write(1, str, ft_strlen(str));
	if (data->flags & FLAG_LEFT_ALIGN)
		while (padlen-- > 0)
			write(1, &padding, 1);
}

static char	*prepare_hex_string(char **hex_str,
			int nb, t_struct *data, const char *base)
{
	char	*prefix;

	if (nb == 0 && data->precision == 0)
	{
		free(*hex_str);
		*hex_str = ft_strdup("");
		if (!*hex_str)
			return (NULL);
	}
	else
	{
		*hex_str = apply_int_precision(*hex_str, data);
		if (!*hex_str)
			return (NULL);
	}
	prefix = "";
	if ((data->flags & FLAG_HASH) && data->var.x != 0)
	{
		if (!ft_strncmp(base, HEXA, 16))
			prefix = "0x";
		else
			prefix = "0X";
	}
	return (prefix);
}

void	ft_printf_hex(t_struct *data, const char *base)
{
	unsigned int	nb;
	char			*hex_str;
	char			*prefix;
	int				len;

	nb = data->var.x;
	hex_str = ft_ulltoa_base(nb, base);
	if (!hex_str)
		return ;
	prefix = prepare_hex_string(&hex_str, nb, data, base);
	if (!hex_str)
		return ;
	len = ft_strlen(hex_str) + ft_strlen(prefix);
	if (data->width > len)
		print_and_pad_with_prefix(prefix, hex_str, data->width - len, data);
	else
		print_with_prefix(prefix, hex_str);
	if (!(data->width > len))
		data->width = len;
	ft_data_len(data, data->width);
	free(hex_str);
}
