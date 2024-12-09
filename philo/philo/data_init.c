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

static void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	philo_nbr;

	philo_nbr = philo->data->philo_nbr;
	if (philo->id % 2 == 1)
	{
		philo->right_fork = &forks[(pos + 1) % philo_nbr];
		philo->left_fork = &forks[pos];
	}
	else
	{
		philo->right_fork = &forks[pos];
		philo->left_fork = &forks[(pos + 1) % philo_nbr];
	}
}

static void	philo_init(t_data *data)
{
	int		i;
	t_philo *philo;

	i = -1;
	while (++i < data->philo_nbr)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->data = data;
		assign_forks(philo, data->forks, i);
	}
}

void    data_init(t_data *data)
{
	int	i;

	i = -1;
	data->end_simulation = false;
	mutex_handle(&data->mutex_data, INIT);
	data->philos = malloc(sizeof(t_philo) * data->philo_nbr);
	if (!data->philos)
		error_exit("Malloc Failed");
	data->forks = malloc(sizeof(t_fork) * data->philo_nbr);
	if (!data->forks)
		error_exit("Malloc Failed");
	while (++i < data->philo_nbr)
	{
		mutex_handle(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i; 
	}
	philo_init(data);
}
