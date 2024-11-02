/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 14:57:55 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(t_struct *data)
{
	int	c;

	c = data->var.c;
	ft_putchar_fd(c, 1);
	ft_data_len(data, 1);
}

void	ft_printf_string(t_struct *data)
{
	char	*str;

	str = data->var.s;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		ft_data_len(data, 6);
		return ;
	}
	ft_putstr_fd(str, 1);
	ft_data_len(data, ft_strlen(str));
}

void	ft_printf_pointer(t_struct *data)
{
	void	*ptr;
	int		len;

	ptr = data->var.p;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		ft_data_len(data, 5);
		return ;
	}
	len = ft_pointer_fd((unsigned long long)ptr, "0123456789abcdef");
	ft_data_len(data, len);
}

void	ft_printf_int(t_struct *data)
{
	int	nb;
	int	len;

	nb = data->var.i;
	len = ft_putnum_fd(nb, 1);
	ft_data_len(data, len);
}

void	ft_printf_percentage(t_struct *data)
{
	ft_putchar_fd('%', 1);
	ft_data_len(data, 1);
}
