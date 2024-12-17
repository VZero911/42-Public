/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 03:28:58 by marvin            #+#    #+#             */
/*   Updated: 2024/12/07 03:28:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static const char *is_valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Only Positive Value !");
	if (!(*str >= '0' && *str <= '9'))
		error_exit("Not A Number !");
	number = str;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		len++;
	}
	if (len > 10)
		error_exit("Value too Big !");
	return (number);
}

static long	ft_atol(const char *str)
{
	long	num;
	
	num = 0;
	str = is_valid_input(str);
	while (*str >= '0' && *str <= '9')
		num = (num * 10) + (*str++ - 48);
	if (num > INT_MAX)
		error_exit("INT_MAX is the limit");
	if (*str != '\0')
		error_exit("Should not have other characters than digits !");
	return (num);
}

static int	init_mutex(t_data *data)
{
	int i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(data->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(data->meal_check), NULL))
		return (1);
	return (0);
}

static int	init_philos(t_data *data)
{
	int i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		data->philos[i].id = i;
		data->philos[i].x_ate = 0;
		data->philos[i].left_fork_id = i;
		data->philos[i].right_fork_id = (i + 1) % data->nb_philo;
		data->philos[i].last_meal = 0;
		data->philos[i].data = data;
	}
	return (0);
}

int	data_init(t_data *data, char **argv)
{
	data->nb_philo = ft_atol(argv[1]);
	data->time_death = ft_atol(argv[2]);
	data->time_eat = ft_atol(argv[3]);
	data->time_sleep = ft_atol(argv[4]);
	data->full = 0;
	data->has_died = 0;
	if ( data->time_death < 60 || data->time_eat < 60
		|| data->time_sleep < 60)
		return (error_exit("Timestamp should be bigger than 60 ms"), 1);
	if (data->nb_philo < 2 || data->nb_philo > 250)
		return (1);
	if (argv[5])
	{
		data->nb_eat = ft_atol(argv[5]);
		if (data->nb_eat <= 0)
			return (1);
	}
	else
		data->nb_eat = -1;
	if (init_mutex(data))
		return (2);
	init_philos(data);
	return (0);
}
