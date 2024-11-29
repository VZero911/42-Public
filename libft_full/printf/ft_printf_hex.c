/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 23:57:26 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_hex_low(unsigned int nb)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (nb >= 16)
		len += ft_putnbr_hex_low(nb / 16);
	ft_putchar_fd(base[nb % 16], 1);
	len++;
	return (len);
}

int	ft_putnbr_hex_up(unsigned int nb)
{
	char	*base;
	int		len;

	base = "0123456789ABCDEF";
	len = 0;
	if (nb >= 16)
		len += ft_putnbr_hex_up(nb / 16);
	ft_putchar_fd(base[nb % 16], 1);
	len ++;
	return (len);
}
