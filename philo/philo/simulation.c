/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 05:43:15 by marvin            #+#    #+#             */
/*   Updated: 2024/12/17 05:43:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->left_fork_id]));
	action_print(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork_id]));
	action_print(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->meal_check));
	action_print(data, philo->id, "is eating");
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&(data->meal_check));
	precise_usleep(data->time_eat, data);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(data->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork_id]));	
}

void	*start_routine(void *void_philo)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)void_philo;
	data = philo->data;
	if (data->nb_philo == 1)
	{
		action_print(data, philo->id, "has taken a fork");
		precise_usleep(data->time_death, data);
		return (NULL);
	}
	if (philo->id % 2)
		usleep(15000);
	while (!(data->has_died))
	{
		philo_eats(philo);
		if (data->full)
			break ;
		action_print(data, philo->id, "is sleeping");
		precise_usleep(data->time_sleep, data);
		action_print(data, philo->id, "is thinking");
	}
	return (NULL);
}

void	destroy_program(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->writing));
	pthread_mutex_destroy(&(data->meal_check));
}

void	shinigami(t_data *data, t_philo *philos)
{
	int	i;

	while (!(data->full))
	{
		i = -1;
		while (++i < data->nb_philo && !(data->has_died))
		{
			pthread_mutex_lock(&(data->meal_check));
			if (time_diff(philos[i].last_meal, timestamp()) > data->time_death)
			{
				action_print(data, i, "died");
				data->has_died = 1;
			}
			pthread_mutex_unlock(&(data->meal_check));
			usleep(100);
		}
		if (data->has_died)
			break ;
		i = 0;
		while (data->nb_eat != -1 && i < data->nb_philo 
			&& philos[i].x_ate >= data->nb_eat)
			i++;
		if (i == data->nb_philo)
			data->full = 1;
	}
}

void	start_simulation(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = data->philos;
	data->first_timestamp = timestamp();
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philos[i].thread_id), NULL, start_routine, &(philos[i])))
			return (error_exit("Error creating the threads"));
		philos[i].last_meal = timestamp();
		i++;
	}
	shinigami(data, data->philos);
	destroy_program(data, philos);
	return ;
}