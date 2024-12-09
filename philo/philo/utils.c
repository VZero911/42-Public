/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:53:05 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/09 01:11:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    clean_data(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->philo_nbr)
	{
		mutex_handle(&data->forks[i].fork, DESTROY);
	}
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void    error_exit(const char *error)
{
	
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}