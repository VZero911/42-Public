/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:02:45 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 21:02:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    set_bool(t_mutex *mutex, bool *dest, bool value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

bool	get_bool(t_mutex *mutex, bool *value)
{
	bool	res;

	mutex_handle(mutex, LOCK);
	res = *value;
	mutex_handle(mutex, UNLOCK);
	return (res);
}

void	set_long(t_mutex *mutex, long *dest, long value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

long	get_long(t_mutex *mutex, long *value)
{
	long	res;

	mutex_handle(mutex, LOCK);
	res = *value;
	mutex_handle(mutex, UNLOCK);
	return (res);
}

bool	simulation_finished(t_data *data)
{
    bool stop;

    mutex_handle(&data->mutex_data, LOCK);
    stop = data->simulation_stop;
    mutex_handle(&data->mutex_data, UNLOCK);
    return (stop);
}
