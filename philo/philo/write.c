/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:04:44 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 02:04:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_phcode phcode, t_philo *philo, bool debug)
{
	long	elapsed;
	(void)debug;

	if (simulation_finished(philo->data))
        return ;
	elapsed = get_time(MILLISECOND) - philo->data->start_simulation / 1e3;
	mutex_handle(&philo->data->mutex_write, LOCK);
	if ((phcode == RIGHT_FORK || phcode == LEFT_FORK)
		&& !simulation_finished(philo->data))
		printf(W"%-6ld"RST" %d has taken a fork\n", elapsed ,philo->id);
	else if (phcode == EATING && !simulation_finished(philo->data))
		printf(W"%-6ld"C" %d is eating\n", elapsed ,philo->id);
	else if (phcode == SLEEPING && !simulation_finished(philo->data))
		printf(W"%-6ld"C" %d is sleeping\n", elapsed ,philo->id);
	else if (phcode == THINKING && !simulation_finished(philo->data))
		printf(W"%-6ld"C" %d is thinking\n", elapsed ,philo->id);
	else if (phcode == DIED && !simulation_finished(philo->data))
		printf(RED"%-6ld %d died\n"RST, elapsed , philo->id);
	mutex_handle(&philo->data->mutex_write, UNLOCK);
}