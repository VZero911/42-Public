/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:58:24 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/09 21:32:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->data);
    while (!get_bool(&philo->data->mutex_data, &philo->data->end_simulation))
    {
        printf("Philosopher %d is thinking\n", philo->id);
        mutex_handle(&philo->left_fork->fork, LOCK);
        mutex_handle(&philo->right_fork->fork, LOCK);
        set_long(&philo->data->mutex_data, &philo->last_meal_time, gettimeoftheday());
        set_long(&philo->data->mutex_data, &philo->meals_counter, 
                 get_long(&philo->data->mutex_data, &philo->meals_counter) + 1);
        printf("Philosopher %d is eating\n", philo->id);
        usleep(philo->data->time_to_eat);
        mutex_handle(&philo->left_fork->fork, UNLOCK);
        mutex_handle(&philo->right_fork->fork, UNLOCK);
        printf("Philosopher %d is sleeping\n", philo->id);
        usleep(philo->data->time_to_sleep);
        if (philo->data->meals_limit > 0 &&
            get_long(&philo->data->mutex_data, &philo->meals_counter) >= philo->data->meals_limit)
            set_bool(&philo->data->mutex_data, &philo->full, true);
    }
    return (NULL);
}


void    execute_philo(t_data *data)
{
	int i;

	i = -1;
	if (data->meals_limit == 0)
		return ;
	else
	{
		while (++i < data->philo_nbr)
			thread_handle(&data->philos[i].thread_id, CREATE, start_routine, &data->philos[i]);
		set_bool(&data->mutex_data, &data->ready_to_start, true);
		i = -1;
		while (++i < data->philo_nbr)
		thread_handle(&data->philos[i].thread_id, JOIN, NULL, NULL);
	}
}
