/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:53:05 by jdumay            #+#    #+#             */
/*   Updated: 2025/01/28 18:19:30 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_usleep(long time, t_data *data)
{
	long	start;

	start = timestamp();
	while (1)
	{
		pthread_mutex_lock(&(data->death_mutex));
		if (data->has_died)
		{
			pthread_mutex_unlock(&(data->death_mutex));
			break ;
		}
		pthread_mutex_unlock(&(data->death_mutex));
		if (time_diff(start, timestamp()) >= time)
			break ;
		usleep(50);
	}
}

long	time_diff(long past, long present)
{
	return (present - past);
}

void	action_print(t_data *data, int id, char *string)
{
	pthread_mutex_lock(&(data->death_mutex));
	if (!data->has_died)
	{
		pthread_mutex_lock(&(data->writing));
		printf("%li %i %s\n", timestamp() - data->first_timestamp,
			id + 1, string);
		pthread_mutex_unlock(&(data->writing));
	}
	pthread_mutex_unlock(&(data->death_mutex));
}
