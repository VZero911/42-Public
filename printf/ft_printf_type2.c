/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 21:51:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hex_low(t_struct *data)
{
	unsigned int	nb;
	int				len;

	nb = data->var.x;
	len = ft_putnbr_hex_low(nb);
	ft_data_len(data, len);
}

void	ft_printf_hex_up(t_struct *data)
{
	unsigned int	nb;
	int				len;

	nb = data->var.x;
	len = ft_putnbr_hex_up(nb);
	ft_data_len(data, len);
}
