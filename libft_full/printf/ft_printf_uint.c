/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 21:48:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*prepare_uint_str(unsigned int nb)
{
	char			*nb_str;
	char			*temp;
	int				i;
	unsigned int	n;

	if (nb == 0)
		return (ft_strdup("0"));
	nb_str = ft_calloc(11, sizeof(char));
	if (!nb_str)
		return (NULL);
	n = nb;
	i = 10;
	nb_str[i] = '\0';
	while (n > 0)
	{
		i--;
		nb_str[i] = (n % 10) + '0';
		n /= 10;
	}
	temp = ft_strdup(nb_str + i);
	free(nb_str);
	return (temp);
}

static char	*process_uint_precision(char *nb_str, t_struct *data)
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

static void	handle_uint_width_padding(char *nb_str, t_struct *data)
{
	int		strlen;
	int		padlen;
	char	padding;

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
}

static void	process_uint_special_flags(t_struct *data)
{
	if ((data->flags & FLAG_ZERO_PADDING)
		&& !(data->flags & FLAG_LEFT_ALIGN)
		&& data->precision == -1)
	{
		data->precision = data->width;
		data->width = 0;
	}
}

void	ft_printf_uint(t_struct *data)
{
	unsigned int	nb;
	char			*nb_str;

	nb = data->var.u;
	nb_str = prepare_uint_str(nb);
	if (!nb_str)
		return ;
	if (nb == 0 && data->precision == 0)
	{
		free(nb_str);
		nb_str = ft_strdup("");
		if (!nb_str)
			return ;
	}
	process_uint_special_flags(data);
	nb_str = process_uint_precision(nb_str, data);
	if (!nb_str)
		return ;
	handle_uint_width_padding(nb_str, data);
	free(nb_str);
}
