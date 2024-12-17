/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:53:05 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/17 03:08:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (simulation_finished(data))
			break ;
		elapsed = get_time(MICROSECOND);
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep(rem /2);
		else
		{
			while (get_time(MICROSECOND) - start < usec)
				;
		}
	}
}

long	get_time(t_tcode code)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		error_exit("Gettimeoftheday failed");
	if (code == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (code == MILLISECOND)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (code == MICROSECOND)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_exit("Wrong Input");
	return (0);
}

void    wait_all_threads(t_data *data)
{
	while (!get_bool(&data->mutex_data, &data->ready_to_start))
		usleep(100);
}


void    clean_data(t_data *data)
{
	int i;

	i = -1;
	if (data->forks)
	{
		while (++i < data->philo_nbr)
		{
			mutex_handle(&data->forks[i].fork, DESTROY);
		}
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
}

void    error_exit(const char *error)
{
	
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}