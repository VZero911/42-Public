/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:58:24 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/11 02:27:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void eating(t_philo *philo)
{
    t_fork *left_fork;
    t_fork *right_fork;

	right_fork = philo->right_fork;
	left_fork = philo->left_fork;
    mutex_handle(&left_fork->fork, LOCK);
	write_status(LEFT_FORK, philo, MODE);
    mutex_handle(&right_fork->fork, LOCK);
	write_status(RIGHT_FORK, philo, MODE);
    set_long(&philo->mutex_philo, &philo->last_meal_time, get_time(MILLISECOND));
	philo->meals_counter++;
	write_status(EATING, philo, MODE);
    precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->philo_nbr > 0
		&& philo->meals_counter == philo->data->meals_limit)
    	set_bool(&philo->mutex_philo, &philo->full, true);
	mutex_handle(&left_fork->fork, UNLOCK);
    mutex_handle(&right_fork->fork, UNLOCK);
}


void    *start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->data);
	while (!simulation_finished(philo->data))
	{
		if (philo->full)
			break ;
		eating(philo);
		// sleeping();
		// thinking(philo);
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
		data->start_simulation = get_time(MICROSECOND);
		set_bool(&data->mutex_data, &data->ready_to_start, true);
		i = -1;
		while (++i < data->philo_nbr)
			thread_handle(&data->philos[i].thread_id, JOIN, NULL, NULL);
		
	}
}
