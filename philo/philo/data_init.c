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

static const char	*is_valid_input(const char *str, int *error)
{
	int			len;
	const char	*number;

	len = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		(*error) = 1;
	if (!(*str >= '0' && *str <= '9'))
		(*error) = 1;
	number = str;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		len++;
	}
	if (len > 10)
		(*error) = 1;
	return (number);
}

static long	ft_atol(const char *str, int *error)
{
	long	num;

	num = 0;
	str = is_valid_input(str, error);
	while (*str >= '0' && *str <= '9')
		num = (num * 10) + (*str++ - 48);
	if (num > INT_MAX)
		(*error) = 1;
	if (*str != '\0')
		(*error) = 1;
	return (num);
}

static int	init_mutex(t_data *data)
{
	int	i;

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
	if (pthread_mutex_init(&(data->death_mutex), NULL))
		return (1);
	return (0);
}

static int	init_philos(t_data *data)
{
	int	i;

	i = data->nb_philo;
	data->full = 0;
	data->has_died = 0;
	while (--i >= 0)
	{
		data->philos[i].id = i;
		data->philos[i].x_ate = 0;
		data->philos[i].left_fork_id = i;
		data->philos[i].right_fork_id = (i + 1) % data->nb_philo;
		data->philos[i].last_meal = 0;
		data->philos[i].is_full = 0;
		data->philos[i].data = data;
	}
	return (0);
}

int	data_init(t_data *data, char **argv)
{
	int	error;

	error = 0;
	data->nb_philo = ft_atol(argv[1], &error);
	data->time_death = ft_atol(argv[2], &error);
	data->time_eat = ft_atol(argv[3], &error);
	data->time_sleep = ft_atol(argv[4], &error);
	if (argv[5])
		data->nb_eat = ft_atol(argv[5], &error);
	else
		data->nb_eat = -1;
	if (error)
		return (1);
	if (data->nb_philo < 1 || data->nb_philo > 250)
		return (3);
	if (data->time_death < 60 || data->time_eat < 60 || data->time_sleep < 60)
		return (4);
	if (data->nb_eat != -1 && data->nb_eat <= 0)
		return (5);
	if (init_mutex(data))
		return (2);
	init_philos(data);
	return (0);
}
