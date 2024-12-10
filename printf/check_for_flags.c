/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 12:08:40 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_for_precision(char **current, t_struct *data)
{
	if (**current == '.')
	{
		data->flags |= FLAG_PRECISION;
		(*current)++;
		data->precision = 0;
		while (**current && ft_isdigit(**current))
		{
			data->precision = (data->precision * 10) + ((**current) - '0');
			(*current)++;
		}
	}
}

void	check_for_width(char **current, t_struct *data)
{
	if (ft_isdigit(**current))
	{
		data->width = 0;
		while (ft_isdigit(**current))
		{
			data->width = (data->width * 10) + ((**current) - '0');
			(*current)++;
		}
	}
}

void	check_for_flags(char **current, t_struct *data)
{
	data->flags = 0;
	data->width = 0;
	data->precision = -1;
	while (**current && ft_strchr(FLAGS, **current))
	{
		if (**current == '-')
			data->flags |= FLAG_LEFT_ALIGN;// ou 1 si ya rien 0 si quelque chose assigne = + 1 
		else if (**current == '0' && !(data->flags & FLAG_LEFT_ALIGN))
			data->flags |= FLAG_ZERO_PADDING;// + 2
		else if (**current == '#')
			data->flags |= FLAG_HASH;// + 4
		else if (**current == '+')
			data->flags |= FLAG_PLUS;
		else if (**current == ' ' && !(data->flags & FLAG_PLUS))
			data->flags |= FLAG_SPACE;
		(*current)++;
	}
	if (**current)
		check_for_width(current, data);
	if (**current)
		check_for_precision(current, data);
}
