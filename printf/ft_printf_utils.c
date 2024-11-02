/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 01:19:11 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_data_len(t_struct *data, int len)
{
	data->len += len;
}

int	ft_pointer_fd(unsigned long long ptr, char *base)
{
	int		len;
	char	buffer[20];
	int		i;

	buffer[19] = 0;
	i = 18;
	len = 2;
	if (ptr == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	while (ptr > 0)
	{
		buffer[i--] = base[ptr % 16];
		ptr /= 16;
		len ++;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';
	ft_putstr_fd(&buffer[i], 1);
	return (len);
}

int	ft_putnum_fd(int nb, int fd)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		len++;
		nb *= -1;
	}
	if (nb >= 10)
		len += ft_putnum_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	len++;
	return (len);
}

int	ft_putunum_fd(unsigned int nb, int fd)
{
	int	len;

	len = 0;
	if (nb >= 10)
		len += ft_putunum_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	len++;
	return (len);
}
