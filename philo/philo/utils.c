/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:53:05 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/17 06:52:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Gettimeofday failed");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_usleep(long time, t_data *data)
{
	long	start;

	start = timestamp();
	while (!(data->has_died))
	{
		if (time_diff(start, timestamp() >= time))
			break ;
		usleep(25);
	}
}

long	time_diff(long past, long present)
{
	return (present - past);
}

void	action_print(t_data *data, int id, char *string)
{
	pthread_mutex_lock(&(data->writing));
	if (!(data->has_died))
	{
		printf("%li ", timestamp() - data->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(data->writing));
	return ;
}