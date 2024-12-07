/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:57:49 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/07 03:37:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static const char *is_valid_input(const char *str)
{
	int			len;
	const char	*number;

	while(is_space(str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Only Positive Value !");
	if (!is_digit(*str))
		error_exit("Not A Number !");
	number = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		error_exit("Value too Big !");
	return (number);
}

static long	ft_atol(const char *str)
{
	long	num;
	
	num = 0;
	str = is_valid_input(str);
	while (is_digit(str))
		num = (num * 10) + (*str++ - 48);
	if (num > INT_MAX)
		error_exit("INT_MAX is the limit");
	return (num);
}

void    parse_input(t_data *data, char **argv)
{
	data->philo_nbr = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]) * 1e3;
	data->time_to_eat = ft_atol(argv[3]) * 1e3;
	data->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (argv[5])
		data->meals_limit = ft_atol(argv[5]);
	else
		data->meals_limit = -1;
	if (data->time_to_die < 6e4
		|| data->time_to_eat < 6e4
		|| data->time_to_sleep < 6e4)
		error_exit("Use timestamps bigger than 60 ms");
}