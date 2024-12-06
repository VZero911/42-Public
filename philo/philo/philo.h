/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:20:17 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/06 18:56:38 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/wait.h>
# include <limits.h>

typedef struct t_data;
typedef pthread_mutex_t t_mutex;

typedef struct s_fork
{
	t_mutex fork;
	int     fork_id;
}   	t_fork;

typedef struct s_philo
{
	int     	id;
	long    	meals_counter;
	long    	last_meal_time;
	bool		full;
	pthread_t	thread_id;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data  	*data;
}   	t_philo;

typedef struct s_data
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_limit;
	long	start_simulation;
	bool	end_simulation;
	t_fork  *forks;
	t_philo *philos;
}   t_data;

void    error_exit(const char *error);

#endif