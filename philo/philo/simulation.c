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

// void	philo_eats(t_philo *philo)
// {

// }

void	*start_routine(void *void_philo)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = (t_philo *)void_philo;
	data = philo->data;
	while (!data->has_died)
	{
		philo_eats(philo);
		if (data->all_ate)
			break ;
		action_print(data, philo->id, "is sleeping");
		precise_usleep(data->time_sleep, data);
		action_print(data, philo->id, "is thinking");
	}
	return (NULL);
}

// void	shinigami(t_data *data, t_philo *philos)
// {

// }

void    start_simulation(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = data->philos;
	data->first_timestamp = timestamp();
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philos[i].thread_id), NULL,  start_routine, &(philos[i])))
			return (error_exit("Error creating the threads"));
		philos->last_meal = timestamp();
		i++;
	}
	// shinigami(data, data->philos);
	i = -1;
	while (++i < data->nb_philo)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->writing));
}
