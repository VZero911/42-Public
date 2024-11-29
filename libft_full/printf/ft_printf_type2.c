/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 23:57:35 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printf_uint(t_struct *data)
{
	unsigned int	nb;
	int				len;

	nb = data->var.u;
	len = ft_putunum_fd(nb, 1);
	ft_data_len(data, len);
}

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
