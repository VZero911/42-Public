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
	int		first;
	int		second;

	data = philo->data;
	first = philo->left_fork_id;
	second = philo->right_fork_id;
	pthread_mutex_lock(&(data->forks[first]));
	action_print(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->forks[second]));
	action_print(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->meal_check));
	action_print(data, philo->id, "is eating");
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&(data->meal_check));
	precise_usleep(data->time_eat, data);
	pthread_mutex_lock(&(data->meal_check));
	philo->x_ate++;
	if (philo->x_ate == data->nb_eat)
		philo->is_full = 1;
	pthread_mutex_unlock(&(data->meal_check));
	pthread_mutex_unlock(&(data->forks[first]));
	pthread_mutex_unlock(&(data->forks[second]));
}

void	*routine(void *void_philo)
{
	t_philo	*philo;
	t_data	*data;
	int		local_is_full;

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
	while (1)
	{
		pthread_mutex_lock(&(data->meal_check));
		local_is_full = philo->is_full;
		pthread_mutex_unlock(&(data->meal_check));
		pthread_mutex_lock(&(data->death_mutex));
		if (data->has_died || data->full || local_is_full)
		{
			pthread_mutex_unlock(&(data->death_mutex));
			break ;
		}
		pthread_mutex_unlock(&(data->death_mutex));
		philo_eats(philo);
		pthread_mutex_lock(&(data->meal_check));
		local_is_full = philo->is_full;
		pthread_mutex_unlock(&(data->meal_check));
		pthread_mutex_lock(&(data->death_mutex));
		if (data->has_died || data->full || local_is_full)
		{
			pthread_mutex_unlock(&(data->death_mutex));
			break ;
		}
		pthread_mutex_unlock(&(data->death_mutex));
		action_print(data, philo->id, "is sleeping");
		precise_usleep(data->time_sleep, data);
		action_print(data, philo->id, "is thinking");
	}
	return (NULL);
}

void	shinigami(t_data *data)
{
	int		i;
	long	time_since_meal;
	int		philo_is_full;
	int		count;

	while (1)
	{
		i = -1;
		while (++i < data->nb_philo)
		{
			pthread_mutex_lock(&(data->meal_check));
			time_since_meal = time_diff(data->philos[i].last_meal, timestamp());
			philo_is_full = data->philos[i].is_full;
			pthread_mutex_unlock(&(data->meal_check));
			pthread_mutex_lock(&(data->death_mutex));
			if (!data->has_died && !philo_is_full
				&& time_since_meal > data->time_death)
			{
				pthread_mutex_unlock(&(data->death_mutex));
				action_print(data, data->philos[i].id, "died");
				pthread_mutex_lock(&(data->death_mutex));
				data->has_died = 1;
				pthread_mutex_unlock(&(data->death_mutex));
				return ;
			}
			pthread_mutex_unlock(&(data->death_mutex));
			usleep(100);
		}
		if (data->nb_eat != -1)
		{
			count = 0;
			i = -1;
			while (++i < data->nb_philo)
			{
				pthread_mutex_lock(&(data->meal_check));
				if (data->philos[i].x_ate >= data->nb_eat)
					count++;
				pthread_mutex_unlock(&(data->meal_check));
			}
			pthread_mutex_lock(&(data->death_mutex));
			if (count == data->nb_philo)
			{
				data->full = 1;
				pthread_mutex_unlock(&(data->death_mutex));
				return ;
			}
			pthread_mutex_unlock(&(data->death_mutex));
		}
	}
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
	pthread_mutex_destroy(&(data->death_mutex));
}

int	start_simulation(t_data *data)
{
	int		i;
	t_philo	*phil;

	i = 0;
	phil = data->philos;
	data->first_timestamp = timestamp();
	while (i < data->nb_philo)
	{
		if (pthread_create(&(phil[i].thread_id), NULL, routine, &(phil[i])))
			return (1);
		pthread_mutex_lock(&(data->meal_check));
		phil[i].last_meal = timestamp();
		pthread_mutex_unlock(&(data->meal_check));
		i++;
	}
	shinigami(data);
	destroy_program(data, phil);
	return (0);
}
