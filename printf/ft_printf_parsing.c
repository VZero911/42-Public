/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 20:24:11 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_get_specifier(char c)
{
	if (c == 'c')
		return (SPECIFIER_CHAR);
	if (c == 's')
		return (SPECIFIER_STRING);
	if (c == 'p')
		return (SPECIFIER_POINTER);
	if (c == 'd' || c == 'i')
		return (SPECIFIER_INT);
	if (c == 'u')
		return (SPECIFIER_UNSIGNED);
	if (c == 'x')
		return (SPECIFIER_HEX_LOW);
	if (c == 'X')
		return (SPECIFIER_HEX_UP);
	if (c == '%')
		return (SPECIFIER_PERCENTAGE);
	return (SPECIFIER_NONE);
}

t_var	ft_get_var(t_struct *data, va_list *args)
{
	t_var	var;

	var.p = NULL;
	if (data->type == SPECIFIER_CHAR)
		var.c = va_arg(*args, int);
	else if (data->type == SPECIFIER_STRING)
		var.s = va_arg(*args, char *);
	else if (data->type == SPECIFIER_POINTER)
		var.p = va_arg(*args, void *);
	else if (data->type == SPECIFIER_INT)
		var.i = va_arg(*args, int);
	else if (data->type == SPECIFIER_UNSIGNED)
		var.u = va_arg(*args, unsigned int);
	else if (data->type == SPECIFIER_HEX_LOW || data->type == SPECIFIER_HEX_UP)
		var.x = va_arg(*args, unsigned int);
	return (var);
}

void	ft_get_data(const char **str, va_list *args, t_struct *data)
{
	char	*current;

	current = (char *)(*str) + 1;
	data->type = ft_get_specifier(*current);
	if (ft_strchr(SPECIFIER, *current) && *current)
	{
		data->var = ft_get_var(data, args);
		*str = current;
	}
}

void	ft_printf_data(t_struct *data)
{
	if (data->type == SPECIFIER_CHAR)
		ft_printf_char(data);
	else if (data->type == SPECIFIER_STRING)
		ft_printf_string(data);
	else if (data->type == SPECIFIER_POINTER)
		ft_printf_pointer(data);
	else if (data->type == SPECIFIER_INT)
		ft_printf_int(data);
	else if (data->type == SPECIFIER_UNSIGNED)
		ft_printf_uint(data);
	else if (data->type == SPECIFIER_PERCENTAGE)
		ft_printf_percentage(data);
	else if (data->type == SPECIFIER_HEX_LOW)
		ft_printf_hex_low(data);
	else if (data->type == SPECIFIER_HEX_UP)
		ft_printf_hex_up(data);
}

int	ft_printf_parsing(const char *str, va_list *args)
{
	int			len;
	t_struct	data;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ft_bzero(&data, sizeof(t_struct));
			ft_get_data(&str, args, &data);
			ft_printf_data(&data);
			len += data.len;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		str++;
	}
	return (len);
}
