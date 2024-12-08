/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:53:05 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/08 18:56:46 by jdumay           ###   ########.fr       */
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
    free(data->forks);
    free(data->philos);
}

void    error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}