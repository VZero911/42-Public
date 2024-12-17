/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:58:24 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/17 03:35:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_philo *philo)
{
	t_fork	*left_fork;
	t_fork	*right_fork;

	left_fork = philo->left_fork;
	right_fork = philo->right_fork;
	if (simulation_finished(philo->data))
		return;
	mutex_handle(&left_fork->fork, LOCK);
	write_status(LEFT_FORK, philo, MODE);
	if (simulation_finished(philo->data))
	{
		mutex_handle(&left_fork->fork, UNLOCK);
		return;
	}
	mutex_handle(&right_fork->fork, LOCK);
	write_status(RIGHT_FORK, philo, MODE);
	write_status(EATING, philo, MODE);
	set_long(&philo->mutex_philo, &philo->last_meal_time, get_time(MILLISECOND));
	precise_usleep(philo->data->time_to_eat, philo->data);
	philo->meals_counter++;
	if (philo->data->meals_limit > 0 && philo->meals_counter >= philo->data->meals_limit)
	    set_bool(&philo->mutex_philo, &philo->full, true);
	mutex_handle(&left_fork->fork, UNLOCK);
	mutex_handle(&right_fork->fork, UNLOCK);
}

void *start_routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    if (philo->id % 2)
        precise_usleep(philo->data->time_to_eat / 10, philo->data);
    wait_all_threads(philo->data);
    while (!simulation_finished(philo->data))
    {
        if (philo->full)
            break;
        eating(philo);
        if (simulation_finished(philo->data))
            break;
        write_status(SLEEPING, philo, MODE);
        precise_usleep(philo->data->time_to_sleep, philo->data);
        if (simulation_finished(philo->data))
            break;
        write_status(THINKING, philo, MODE);
    }
    return (NULL);
}

void    *monitor_death(void *arg)
{
    t_data  *data;
    long    current_time;
    int     i;
    int     full_philos;

    data = (t_data *)arg;

    while (!simulation_finished(data))
    {
        full_philos = 0;
        i = -1;
        while (++i < data->philo_nbr)
        {
            current_time = get_time(MILLISECOND);
            mutex_handle(&data->philos[i].mutex_philo, LOCK);
            if (!data->philos[i].full && 
                (current_time - data->philos[i].last_meal_time) >= data->time_to_die)
            {
                write_status(DIED, &data->philos[i], MODE);
                set_bool(&data->mutex_data, &data->simulation_stop, true);
                mutex_handle(&data->philos[i].mutex_philo, UNLOCK);
				return (NULL);
            }
            if (data->philos[i].full)
                full_philos++;
            mutex_handle(&data->philos[i].mutex_philo, UNLOCK);
        }
        if (full_philos == data->philo_nbr)
        {
            set_bool(&data->mutex_data, &data->simulation_stop, true);
            return (NULL);
        }
        precise_usleep(5, data);
    }
    return (NULL);
}

void    execute_philo(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	if (data->meals_limit == 0)
		return ;
	else
	{
		thread_handle(&monitor_thread, CREATE, monitor_death, data);
		while (++i < data->philo_nbr)
			thread_handle(&data->philos[i].thread_id, CREATE, start_routine, &data->philos[i]);
		data->start_simulation = get_time(MICROSECOND);
		set_bool(&data->mutex_data, &data->ready_to_start, true);
		i = -1;
		while (++i < data->philo_nbr)
			thread_handle(&data->philos[i].thread_id, JOIN, NULL, NULL);
		thread_handle(&monitor_thread, JOIN, NULL, NULL);
	}
}
